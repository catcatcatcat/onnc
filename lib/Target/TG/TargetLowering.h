//===- TargetLowering.h ---------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef TARGET_TARGET_TG_TARGET_LOWERING_H
#define TARGET_TARGET_TG_TARGET_LOWERING_H

#include "ComputeOperator.h"
#include "TGBackend.h"
#include <memory>
#include <onnc/IR/Module.h>
#include <onnx/common/ir.h>

namespace onnc {

class Module;

class TargetLowering
{
public:
  using ComputeGraph = std::vector<std::unique_ptr<ComputeOperator2> >;

public:
  TargetLowering(TGBackend *pBackend) : m_pBackend(pBackend) {}

  virtual ~TargetLowering() = default;

  // do something before ISelLowering
  virtual void PrepareISelLowering(Module &pModule) { return; };

  // Lowering ONNX IR to Compute IR
  virtual void
  ISelLowering(const ::onnx::Graph *pOnnxGraph, TGBackend::Instructions& pInsns);

  virtual ComputeOperator2 *LowerOperation(const ::onnx::Node &pNode,
                                           ComputeGraph &pGraph) = 0;

protected:
  TGBackend *m_pBackend; // NOLINT
};

} // namespace onnc

#endif
