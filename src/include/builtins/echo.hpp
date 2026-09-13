#pragma once
#include "executable.hpp"

namespace builtin {

class Echo : public shell::IExecutable {
public:
  Echo() = default;

  explicit Echo(const std::string &cmd);

  explicit Echo(const std::string &cmd, const std::vector<std::string> &argv);

  std::string GetCmd() const override;

  std::vector<std::string> GetArgv() const override;

  utils::LoopDecision Run() const override;

private:
  std::string cmd_m;
  std::vector<std::string> argv_m;
};
}
