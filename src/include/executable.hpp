#pragma once

#include <string>
#include <vector>

#include "utils.hpp"

namespace shell {

class ExecutableContext {
 public:
  ExecutableContext() = default;

  ExecutableContext(const std::string& cmd);

  ExecutableContext(const std::string& cmd, const std::vector<std::string>& argv);

  std::string GetCmd() const;

  std::vector<std::string> GetArgv() const;

 private:
  std::string cmd_m;
  std::vector<std::string> argv_m;
};

class IExecutable {
 public:
  virtual ~IExecutable() = default;

  virtual utils::LoopDecision Run(const ExecutableContext& context) const = 0;
};

class Executable : public IExecutable {
 public:
  Executable() = default;

  utils::LoopDecision Run(const ExecutableContext& context) const override;
};

}  // namespace shell
