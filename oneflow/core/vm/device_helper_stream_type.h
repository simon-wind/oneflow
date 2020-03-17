#ifndef ONEFLOW_CORE_VM_DEVICE_HELPER_VM_STREAM_TYPE_H_
#define ONEFLOW_CORE_VM_DEVICE_HELPER_VM_STREAM_TYPE_H_

#include "oneflow/core/vm/stream_type.h"

namespace oneflow {
namespace vm {

class Scheduler;
class InstructionMsg;

class DeviceHelperStreamType final : public StreamType {
 public:
  DeviceHelperStreamType() = default;
  ~DeviceHelperStreamType() = default;

  static const StreamTypeId kStreamTypeId = 3;

  ObjectMsgPtr<InstructionMsg> CudaMalloc(uint64_t logical_object_id, size_t size) const;
  ObjectMsgPtr<InstructionMsg> CudaFree(uint64_t logical_object_id) const;

  void InitDeviceCtx(std::unique_ptr<DeviceCtx>* device_ctx, Stream* stream) const override {}

  void InitInstructionStatus(const Stream& stream,
                             InstructionStatusBuffer* status_buffer) const override;
  void DeleteInstructionStatus(const Stream& stream,
                               InstructionStatusBuffer* status_buffer) const override;
  bool QueryInstructionStatusDone(const Stream& stream,
                                  const InstructionStatusBuffer& status_buffer) const override;
  void Run(InstrChain* instr_chain) const override;
  ObjectMsgPtr<StreamDesc> MakeRemoteStreamDesc(const Resource& resource,
                                                int64_t this_machine_id) const override;
};

}  // namespace vm
}  // namespace oneflow

#endif  // ONEFLOW_CORE_VM_DEVICE_HELPER_VM_STREAM_TYPE_H_
