#pragma once

#include <string>
#include <vector>

#include "utils.hpp"

namespace shell {

class IExecutable {
 public:
  virtual utils::LoopDecision Run() const = 0;

  virtual std::string GetCmd() const = 0;

  virtual std::vector<std::string> GetArgv() const = 0;
};

class Executable : public IExecutable {
 public:
  Executable() = default;

  explicit Executable(const std::string& cmd);

  explicit Executable(const std::string& cmd, const std::vector<std::string>& argv);

  std::string GetCmd() const override;

  std::vector<std::string> GetArgv() const override;

  utils::LoopDecision Run() const override;

 private:
  std::string cmd_m;
  std::vector<std::string> argv_m;
};

}  // namespace shell
