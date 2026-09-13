#pragma once

#include "executable.hpp"
#include "utils.hpp"
#include <memory>

namespace shell {

class CommandExecutor {
public:
  CommandExecutor() = delete;

  CommandExecutor(std::shared_ptr<IExecutable> exe);

  std::shared_ptr<IExecutable> GetExe() const;

  utils::LoopDecision Execute();

private:
  std::shared_ptr<IExecutable> exe_m;
};

} // shell ends
