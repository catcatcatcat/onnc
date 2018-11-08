//===- Profile.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===--------------------------------------------------------------===//
#ifndef ONNC_IR_COMPUTE_OPERATOR_PROFILE_H
#define ONNC_IR_COMPUTE_OPERATOR_PROFILE_H
#include <onnc/IR/ComputeOperator.h>
#include <onnc/IR/ComputeVisitor.h>
#include <onnc/IR/Compute/Attributes.h>
#include <onnc/Support/DataTypes.h>
#include <onnc/Support/IOStream.h>
#include <linux/perf_event.h>

namespace onnc {

class Profile : public ComputeOperator
{
public:
  typedef uint64_t Interval;
  static char ID;

public:
  Profile();

  // clang-format off
  
  // clang-format on

  // shallow copy constructor.
  Profile(const Profile &pCopy);

  //virtual ~Profile() { }
  ~Profile();

  // clang-format off
  // Attributes getters
  void getPMUCounter();

  // Attributes setters
  void start();
  void stop();

  // Inputs setters

  // Outputs setters

  // clang-format on
  void accept(ComputeVisitor& pVisitor) override { pVisitor.visit(*this); }

  void accept(ComputeVisitor& pVisitor) const override { pVisitor.visit(*this); }

  void printAttributes(std::ostream& pOS) const override { pOS << "Hello, world.\n"; }

  static bool classof(const ComputeOperator* pOp);

private:
  // clang-format off
  Profile::Interval m_Interval, m_EventType;
  bool m_bIsActive;  
  // clang-format on
};

} // namespace of onnc

#endif