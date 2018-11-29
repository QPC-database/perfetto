/*
 * Copyright (C) 2017 The Android Open Source Project
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

/*******************************************************************************
 * AUTOGENERATED - DO NOT EDIT
 *******************************************************************************
 * This file has been generated from the protobuf message
 * perfetto/config/trace_config.proto
 * by
 * ../../tools/proto_to_cpp/proto_to_cpp.cc.
 * If you need to make changes here, change the .proto file and then run
 * ./tools/gen_tracing_cpp_headers_from_protos
 */

#include "perfetto/tracing/core/trace_config.h"

#include "perfetto/config/data_source_config.pb.h"
#include "perfetto/config/trace_config.pb.h"

namespace perfetto {

TraceConfig::TraceConfig() = default;
TraceConfig::~TraceConfig() = default;
TraceConfig::TraceConfig(const TraceConfig&) = default;
TraceConfig& TraceConfig::operator=(const TraceConfig&) = default;
TraceConfig::TraceConfig(TraceConfig&&) noexcept = default;
TraceConfig& TraceConfig::operator=(TraceConfig&&) = default;

void TraceConfig::FromProto(const perfetto::protos::TraceConfig& proto) {
  buffers_.clear();
  for (const auto& field : proto.buffers()) {
    buffers_.emplace_back();
    buffers_.back().FromProto(field);
  }

  data_sources_.clear();
  for (const auto& field : proto.data_sources()) {
    data_sources_.emplace_back();
    data_sources_.back().FromProto(field);
  }

  static_assert(sizeof(duration_ms_) == sizeof(proto.duration_ms()),
                "size mismatch");
  duration_ms_ = static_cast<decltype(duration_ms_)>(proto.duration_ms());

  static_assert(sizeof(enable_extra_guardrails_) ==
                    sizeof(proto.enable_extra_guardrails()),
                "size mismatch");
  enable_extra_guardrails_ = static_cast<decltype(enable_extra_guardrails_)>(
      proto.enable_extra_guardrails());

  static_assert(sizeof(lockdown_mode_) == sizeof(proto.lockdown_mode()),
                "size mismatch");
  lockdown_mode_ = static_cast<decltype(lockdown_mode_)>(proto.lockdown_mode());

  producers_.clear();
  for (const auto& field : proto.producers()) {
    producers_.emplace_back();
    producers_.back().FromProto(field);
  }

  statsd_metadata_.FromProto(proto.statsd_metadata());

  static_assert(sizeof(write_into_file_) == sizeof(proto.write_into_file()),
                "size mismatch");
  write_into_file_ =
      static_cast<decltype(write_into_file_)>(proto.write_into_file());

  static_assert(
      sizeof(file_write_period_ms_) == sizeof(proto.file_write_period_ms()),
      "size mismatch");
  file_write_period_ms_ = static_cast<decltype(file_write_period_ms_)>(
      proto.file_write_period_ms());

  static_assert(
      sizeof(max_file_size_bytes_) == sizeof(proto.max_file_size_bytes()),
      "size mismatch");
  max_file_size_bytes_ =
      static_cast<decltype(max_file_size_bytes_)>(proto.max_file_size_bytes());

  guardrail_overrides_.FromProto(proto.guardrail_overrides());

  static_assert(sizeof(deferred_start_) == sizeof(proto.deferred_start()),
                "size mismatch");
  deferred_start_ =
      static_cast<decltype(deferred_start_)>(proto.deferred_start());

  static_assert(sizeof(flush_period_ms_) == sizeof(proto.flush_period_ms()),
                "size mismatch");
  flush_period_ms_ =
      static_cast<decltype(flush_period_ms_)>(proto.flush_period_ms());
  unknown_fields_ = proto.unknown_fields();
}

void TraceConfig::ToProto(perfetto::protos::TraceConfig* proto) const {
  proto->Clear();

  for (const auto& it : buffers_) {
    auto* entry = proto->add_buffers();
    it.ToProto(entry);
  }

  for (const auto& it : data_sources_) {
    auto* entry = proto->add_data_sources();
    it.ToProto(entry);
  }

  static_assert(sizeof(duration_ms_) == sizeof(proto->duration_ms()),
                "size mismatch");
  proto->set_duration_ms(
      static_cast<decltype(proto->duration_ms())>(duration_ms_));

  static_assert(sizeof(enable_extra_guardrails_) ==
                    sizeof(proto->enable_extra_guardrails()),
                "size mismatch");
  proto->set_enable_extra_guardrails(
      static_cast<decltype(proto->enable_extra_guardrails())>(
          enable_extra_guardrails_));

  static_assert(sizeof(lockdown_mode_) == sizeof(proto->lockdown_mode()),
                "size mismatch");
  proto->set_lockdown_mode(
      static_cast<decltype(proto->lockdown_mode())>(lockdown_mode_));

  for (const auto& it : producers_) {
    auto* entry = proto->add_producers();
    it.ToProto(entry);
  }

  statsd_metadata_.ToProto(proto->mutable_statsd_metadata());

  static_assert(sizeof(write_into_file_) == sizeof(proto->write_into_file()),
                "size mismatch");
  proto->set_write_into_file(
      static_cast<decltype(proto->write_into_file())>(write_into_file_));

  static_assert(
      sizeof(file_write_period_ms_) == sizeof(proto->file_write_period_ms()),
      "size mismatch");
  proto->set_file_write_period_ms(
      static_cast<decltype(proto->file_write_period_ms())>(
          file_write_period_ms_));

  static_assert(
      sizeof(max_file_size_bytes_) == sizeof(proto->max_file_size_bytes()),
      "size mismatch");
  proto->set_max_file_size_bytes(
      static_cast<decltype(proto->max_file_size_bytes())>(
          max_file_size_bytes_));

  guardrail_overrides_.ToProto(proto->mutable_guardrail_overrides());

  static_assert(sizeof(deferred_start_) == sizeof(proto->deferred_start()),
                "size mismatch");
  proto->set_deferred_start(
      static_cast<decltype(proto->deferred_start())>(deferred_start_));

  static_assert(sizeof(flush_period_ms_) == sizeof(proto->flush_period_ms()),
                "size mismatch");
  proto->set_flush_period_ms(
      static_cast<decltype(proto->flush_period_ms())>(flush_period_ms_));
  *(proto->mutable_unknown_fields()) = unknown_fields_;
}

TraceConfig::BufferConfig::BufferConfig() = default;
TraceConfig::BufferConfig::~BufferConfig() = default;
TraceConfig::BufferConfig::BufferConfig(const TraceConfig::BufferConfig&) =
    default;
TraceConfig::BufferConfig& TraceConfig::BufferConfig::operator=(
    const TraceConfig::BufferConfig&) = default;
TraceConfig::BufferConfig::BufferConfig(TraceConfig::BufferConfig&&) noexcept =
    default;
TraceConfig::BufferConfig& TraceConfig::BufferConfig::operator=(
    TraceConfig::BufferConfig&&) = default;

void TraceConfig::BufferConfig::FromProto(
    const perfetto::protos::TraceConfig_BufferConfig& proto) {
  static_assert(sizeof(size_kb_) == sizeof(proto.size_kb()), "size mismatch");
  size_kb_ = static_cast<decltype(size_kb_)>(proto.size_kb());

  static_assert(sizeof(fill_policy_) == sizeof(proto.fill_policy()),
                "size mismatch");
  fill_policy_ = static_cast<decltype(fill_policy_)>(proto.fill_policy());
  unknown_fields_ = proto.unknown_fields();
}

void TraceConfig::BufferConfig::ToProto(
    perfetto::protos::TraceConfig_BufferConfig* proto) const {
  proto->Clear();

  static_assert(sizeof(size_kb_) == sizeof(proto->size_kb()), "size mismatch");
  proto->set_size_kb(static_cast<decltype(proto->size_kb())>(size_kb_));

  static_assert(sizeof(fill_policy_) == sizeof(proto->fill_policy()),
                "size mismatch");
  proto->set_fill_policy(
      static_cast<decltype(proto->fill_policy())>(fill_policy_));
  *(proto->mutable_unknown_fields()) = unknown_fields_;
}

TraceConfig::DataSource::DataSource() = default;
TraceConfig::DataSource::~DataSource() = default;
TraceConfig::DataSource::DataSource(const TraceConfig::DataSource&) = default;
TraceConfig::DataSource& TraceConfig::DataSource::operator=(
    const TraceConfig::DataSource&) = default;
TraceConfig::DataSource::DataSource(TraceConfig::DataSource&&) noexcept =
    default;
TraceConfig::DataSource& TraceConfig::DataSource::operator=(
    TraceConfig::DataSource&&) = default;

void TraceConfig::DataSource::FromProto(
    const perfetto::protos::TraceConfig_DataSource& proto) {
  config_.FromProto(proto.config());

  producer_name_filter_.clear();
  for (const auto& field : proto.producer_name_filter()) {
    producer_name_filter_.emplace_back();
    static_assert(sizeof(producer_name_filter_.back()) ==
                      sizeof(proto.producer_name_filter(0)),
                  "size mismatch");
    producer_name_filter_.back() =
        static_cast<decltype(producer_name_filter_)::value_type>(field);
  }
  unknown_fields_ = proto.unknown_fields();
}

void TraceConfig::DataSource::ToProto(
    perfetto::protos::TraceConfig_DataSource* proto) const {
  proto->Clear();

  config_.ToProto(proto->mutable_config());

  for (const auto& it : producer_name_filter_) {
    proto->add_producer_name_filter(
        static_cast<decltype(proto->producer_name_filter(0))>(it));
    static_assert(sizeof(it) == sizeof(proto->producer_name_filter(0)),
                  "size mismatch");
  }
  *(proto->mutable_unknown_fields()) = unknown_fields_;
}

TraceConfig::ProducerConfig::ProducerConfig() = default;
TraceConfig::ProducerConfig::~ProducerConfig() = default;
TraceConfig::ProducerConfig::ProducerConfig(
    const TraceConfig::ProducerConfig&) = default;
TraceConfig::ProducerConfig& TraceConfig::ProducerConfig::operator=(
    const TraceConfig::ProducerConfig&) = default;
TraceConfig::ProducerConfig::ProducerConfig(
    TraceConfig::ProducerConfig&&) noexcept = default;
TraceConfig::ProducerConfig& TraceConfig::ProducerConfig::operator=(
    TraceConfig::ProducerConfig&&) = default;

void TraceConfig::ProducerConfig::FromProto(
    const perfetto::protos::TraceConfig_ProducerConfig& proto) {
  static_assert(sizeof(producer_name_) == sizeof(proto.producer_name()),
                "size mismatch");
  producer_name_ = static_cast<decltype(producer_name_)>(proto.producer_name());

  static_assert(sizeof(shm_size_kb_) == sizeof(proto.shm_size_kb()),
                "size mismatch");
  shm_size_kb_ = static_cast<decltype(shm_size_kb_)>(proto.shm_size_kb());

  static_assert(sizeof(page_size_kb_) == sizeof(proto.page_size_kb()),
                "size mismatch");
  page_size_kb_ = static_cast<decltype(page_size_kb_)>(proto.page_size_kb());
  unknown_fields_ = proto.unknown_fields();
}

void TraceConfig::ProducerConfig::ToProto(
    perfetto::protos::TraceConfig_ProducerConfig* proto) const {
  proto->Clear();

  static_assert(sizeof(producer_name_) == sizeof(proto->producer_name()),
                "size mismatch");
  proto->set_producer_name(
      static_cast<decltype(proto->producer_name())>(producer_name_));

  static_assert(sizeof(shm_size_kb_) == sizeof(proto->shm_size_kb()),
                "size mismatch");
  proto->set_shm_size_kb(
      static_cast<decltype(proto->shm_size_kb())>(shm_size_kb_));

  static_assert(sizeof(page_size_kb_) == sizeof(proto->page_size_kb()),
                "size mismatch");
  proto->set_page_size_kb(
      static_cast<decltype(proto->page_size_kb())>(page_size_kb_));
  *(proto->mutable_unknown_fields()) = unknown_fields_;
}

TraceConfig::StatsdMetadata::StatsdMetadata() = default;
TraceConfig::StatsdMetadata::~StatsdMetadata() = default;
TraceConfig::StatsdMetadata::StatsdMetadata(
    const TraceConfig::StatsdMetadata&) = default;
TraceConfig::StatsdMetadata& TraceConfig::StatsdMetadata::operator=(
    const TraceConfig::StatsdMetadata&) = default;
TraceConfig::StatsdMetadata::StatsdMetadata(
    TraceConfig::StatsdMetadata&&) noexcept = default;
TraceConfig::StatsdMetadata& TraceConfig::StatsdMetadata::operator=(
    TraceConfig::StatsdMetadata&&) = default;

void TraceConfig::StatsdMetadata::FromProto(
    const perfetto::protos::TraceConfig_StatsdMetadata& proto) {
  static_assert(
      sizeof(triggering_alert_id_) == sizeof(proto.triggering_alert_id()),
      "size mismatch");
  triggering_alert_id_ =
      static_cast<decltype(triggering_alert_id_)>(proto.triggering_alert_id());

  static_assert(
      sizeof(triggering_config_uid_) == sizeof(proto.triggering_config_uid()),
      "size mismatch");
  triggering_config_uid_ = static_cast<decltype(triggering_config_uid_)>(
      proto.triggering_config_uid());

  static_assert(
      sizeof(triggering_config_id_) == sizeof(proto.triggering_config_id()),
      "size mismatch");
  triggering_config_id_ = static_cast<decltype(triggering_config_id_)>(
      proto.triggering_config_id());
  unknown_fields_ = proto.unknown_fields();
}

void TraceConfig::StatsdMetadata::ToProto(
    perfetto::protos::TraceConfig_StatsdMetadata* proto) const {
  proto->Clear();

  static_assert(
      sizeof(triggering_alert_id_) == sizeof(proto->triggering_alert_id()),
      "size mismatch");
  proto->set_triggering_alert_id(
      static_cast<decltype(proto->triggering_alert_id())>(
          triggering_alert_id_));

  static_assert(
      sizeof(triggering_config_uid_) == sizeof(proto->triggering_config_uid()),
      "size mismatch");
  proto->set_triggering_config_uid(
      static_cast<decltype(proto->triggering_config_uid())>(
          triggering_config_uid_));

  static_assert(
      sizeof(triggering_config_id_) == sizeof(proto->triggering_config_id()),
      "size mismatch");
  proto->set_triggering_config_id(
      static_cast<decltype(proto->triggering_config_id())>(
          triggering_config_id_));
  *(proto->mutable_unknown_fields()) = unknown_fields_;
}

TraceConfig::GuardrailOverrides::GuardrailOverrides() = default;
TraceConfig::GuardrailOverrides::~GuardrailOverrides() = default;
TraceConfig::GuardrailOverrides::GuardrailOverrides(
    const TraceConfig::GuardrailOverrides&) = default;
TraceConfig::GuardrailOverrides& TraceConfig::GuardrailOverrides::operator=(
    const TraceConfig::GuardrailOverrides&) = default;
TraceConfig::GuardrailOverrides::GuardrailOverrides(
    TraceConfig::GuardrailOverrides&&) noexcept = default;
TraceConfig::GuardrailOverrides& TraceConfig::GuardrailOverrides::operator=(
    TraceConfig::GuardrailOverrides&&) = default;

void TraceConfig::GuardrailOverrides::FromProto(
    const perfetto::protos::TraceConfig_GuardrailOverrides& proto) {
  static_assert(sizeof(max_upload_per_day_bytes_) ==
                    sizeof(proto.max_upload_per_day_bytes()),
                "size mismatch");
  max_upload_per_day_bytes_ = static_cast<decltype(max_upload_per_day_bytes_)>(
      proto.max_upload_per_day_bytes());
  unknown_fields_ = proto.unknown_fields();
}

void TraceConfig::GuardrailOverrides::ToProto(
    perfetto::protos::TraceConfig_GuardrailOverrides* proto) const {
  proto->Clear();

  static_assert(sizeof(max_upload_per_day_bytes_) ==
                    sizeof(proto->max_upload_per_day_bytes()),
                "size mismatch");
  proto->set_max_upload_per_day_bytes(
      static_cast<decltype(proto->max_upload_per_day_bytes())>(
          max_upload_per_day_bytes_));
  *(proto->mutable_unknown_fields()) = unknown_fields_;
}

}  // namespace perfetto
