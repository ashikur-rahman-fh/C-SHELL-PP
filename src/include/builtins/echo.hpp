#pragma once
#include "executable.hpp"

namespace builtin {

class Echo : public shell::IExecutable {
 public:
  Echo() = default;

  utils::LoopDecision Run(const shell::ExecutableContext& context) const override;
};

}  // namespace builtin
