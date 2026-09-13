#pragma once
#include "executable.hpp"
#include "utils.hpp"

namespace builtin {

class Type : public shell::IExecutable {
 public:
  Type() = default;

  utils::LoopDecision Run(const shell::ExecutableContext& context) const override;
};
}  // namespace builtin
