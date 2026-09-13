
#include "exit.hpp"

#include "executable.hpp"
#include "utils.hpp"

namespace builtin {

utils::LoopDecision Exit::Run(const shell::ExecutableContext& context) const {
  return utils::LoopDecision::Break;
}

}  // namespace builtin
