#include "command_executor.hpp"
#include "builtins/builtin.hpp"
#include "executable.hpp"
#include "utils.hpp"
#include "format"
#include <cassert>


namespace shell {
  CommandExecutor::CommandExecutor(const Executable &exe) {
    this -> exe_m = exe;
  }

  Executable CommandExecutor::GetExe() const {
    return this -> exe_m;
  }

  utils::LoopDecision CommandExecutor::Execute() {
    if (builtin::IsBuiltIn(this -> exe_m)) {
      return utils::LoopDecision::Break;
    }
    throw utils::ShellError(std::format("{}: command not found", this -> exe_m.GetCmd()),
      utils::LoopDecision::Continue);
  }

}
