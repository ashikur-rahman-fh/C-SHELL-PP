#pragma once
#include "executable.hpp"
#include "utils.hpp"

namespace builtin {

class Exit : public shell::IExecutable {
 public:
  Exit() = default;

  utils::LoopDecision Run(const shell::ExecutableContext& context) const override;
};
}  // namespace builtin
