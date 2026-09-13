#pragma once

#include "executable.hpp"
#include "utils.hpp"

namespace shell {

class CommandExecutor {
public:
  CommandExecutor() = delete;

  CommandExecutor(const Executable &exe);

  Executable GetExe() const;

  utils::LoopDecision Execute();

private:
  Executable exe_m;
};

} // shell ends
