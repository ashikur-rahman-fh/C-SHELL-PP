#pragma once

#include <memory>

#include "executable.hpp"
#include "utils.hpp"

namespace shell {

class CommandExecutor {
 public:
  CommandExecutor() = delete;

  CommandExecutor(std::shared_ptr<IExecutable> exe);

  std::shared_ptr<IExecutable> GetExe() const;

  utils::LoopDecision Execute(const ExecutableContext& context);

 private:
  std::shared_ptr<IExecutable> exe_m;
};

}  // namespace shell
