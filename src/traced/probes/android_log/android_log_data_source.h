/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SRC_TRACED_PROBES_ANDROID_LOG_ANDROID_LOG_DATA_SOURCE_H_
#define SRC_TRACED_PROBES_ANDROID_LOG_ANDROID_LOG_DATA_SOURCE_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "perfetto/base/paged_memory.h"
#include "perfetto/base/scoped_file.h"
#include "perfetto/base/string_view.h"
#include "perfetto/base/unix_socket.h"
#include "perfetto/base/weak_ptr.h"
#include "src/traced/probes/probes_data_source.h"

namespace perfetto {

class DataSourceConfig;
class TraceWriter;
namespace base {
class TaskRunner;
}

namespace protos {
namespace pbzero {
class AndroidLogPacket;
class AndroidLogPacket_LogEvent;
}  // namespace pbzero
}  // namespace protos

class AndroidLogDataSource : public ProbesDataSource {
 public:
  struct Stats {
    uint64_t num_total = 0;    // Total number of log entries received.
    uint64_t num_failed = 0;   // Parser failures.
    uint64_t num_skipped = 0;  // Messages skipped due to filters.
  };

  // One EventFormat == one line of /system/etc/event-log-tags.
  struct EventFormat {
    std::string name;
    std::vector<std::string> fields;
  };
  static constexpr int kTypeId = 6;

  AndroidLogDataSource(DataSourceConfig,
                       base::TaskRunner*,
                       TracingSessionID,
                       std::unique_ptr<TraceWriter> writer);

  ~AndroidLogDataSource() override;

  // ProbesDataSource implementation.
  void Start() override;
  void Flush(FlushRequestID, std::function<void()> callback) override;

  // Reads the contents of /system/etc/event-log-tags. Virtual for testing.
  virtual std::string ReadEventLogDefinitions();

  // Connects to the /dev/socket/logdr socket. Virtual for testing.
  virtual base::UnixSocketRaw ConnectLogdrSocket();

  // Parses the contents of ReadEventLogDefinitions().
  void ParseEventLogDefinitions();

  const EventFormat* GetEventFormat(int id) const;
  const Stats& stats() const { return stats_; }
  base::WeakPtr<AndroidLogDataSource> GetWeakPtr() const;

 private:
  // Periodic polling task.
  void Tick(bool post_next_task);

  // Parses one line of /system/etc/event-log-tags.
  bool ParseEventLogDefinitionLine(char* line, size_t len);

  // Parses a textual (i.e. tag + message) event, which is the majority of
  // log events. All buffers but the LID_EVENTS contain text events.
  // If parsing fails returns false and leaves the |out_evt| field unset.
  // If parsing succeeds returns true and:
  // - If the event is skipped due to filters, |out_evt| is left unset.
  // - If a new event is aded to the packet, |out_evt| is set to that.
  bool ParseTextEvent(const char* start,
                      const char* end,
                      protos::pbzero::AndroidLogPacket* packet,
                      protos::pbzero::AndroidLogPacket_LogEvent** out_evt);

  // Parses a binary event from the "events" buffer.
  // If parsing fails returns false and leaves the |out_evt| field unset.
  // If parsing succeeds returns true and:
  // - If the event is skipped due to filters, |out_evt| is left unset.
  // - If a new event is aded to the packet, |out_evt| is set to that.
  bool ParseBinaryEvent(const char* start,
                        const char* end,
                        protos::pbzero::AndroidLogPacket* packet,
                        protos::pbzero::AndroidLogPacket_LogEvent** out_evt);

  base::TaskRunner* const task_runner_;
  std::unique_ptr<TraceWriter> writer_;
  base::UnixSocketRaw logdr_sock_;

  // Config parameters coming from the data source section in the trace config.
  uint32_t poll_rate_ms_ = 0;
  int min_prio_ = 0;
  std::string mode_;

  // For filtering events based on tags.
  std::unordered_set<base::StringView> filter_tags_;
  std::vector<char> filter_tags_strbuf_;

  // Lookup map for binary events (log_id=EVENTS). Translates a numeric id into
  // a corresponding field descriptor. This is generated by parsing
  // /system/etc/event-log-tags when starting.
  std::unordered_map<int, EventFormat> event_formats_;

  // Buffer used for parsing. It's safer (read: fails sooner) than using the
  // stack, due to red zones around the boundaries.
  base::PagedMemory buf_;
  Stats stats_;

  base::WeakPtrFactory<AndroidLogDataSource> weak_factory_;  // Keep last.
};

}  // namespace perfetto

#endif  // SRC_TRACED_PROBES_ANDROID_LOG_ANDROID_LOG_DATA_SOURCE_H_
