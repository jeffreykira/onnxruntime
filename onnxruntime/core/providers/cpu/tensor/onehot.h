// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "core/common/common.h"
#include "core/framework/op_kernel.h"

namespace onnxruntime {

template <typename in_type, typename out_type, typename depth_type>
class OneHotOp final : public OpKernel {
 public:
  explicit OneHotOp(const OpKernelInfo& op_kernel_info) : OpKernel(op_kernel_info) {
    int64_t tmp_axis;
    if (op_kernel_info.GetAttr<int64_t>("axis", &tmp_axis).IsOK()) {
      axis_ = tmp_axis;
    }
  }

  Status Compute(OpKernelContext* p_op_kernel_context) const override;

 private:
  ORT_DISALLOW_COPY_ASSIGNMENT_AND_MOVE(OneHotOp);

  int64_t axis_ = -1;
};
}  // namespace onnxruntime
