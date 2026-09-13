
#include "command_executor.hpp"

#include <cassert>
#include <memory>

#include "builtins/builtin.hpp"
#include "executable.hpp"
#include "format"
#include "utils.hpp"

namespace shell {
CommandExecutor::CommandExecutor(std::shared_ptr<IExecutable> exe) {
  this->exe_m = exe;
}

std::shared_ptr<IExecutable> CommandExecutor::GetExe() const {
  return this->exe_m;
}

utils::LoopDecision CommandExecutor::Execute() {
  if (builtin::IsBuiltIn(this->exe_m)) {
    return exe_m->Run();
  }
  throw utils::ShellError(std::format("{}: command not found", this->exe_m->GetCmd()),
                          utils::LoopDecision::Continue);
}

}  // namespace shell
