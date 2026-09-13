#pragma once

#include <string>
#include <vector>

namespace shell {
class Executable {
public:
  Executable() = default;

  explicit Executable(const std::string &cmd);

  explicit Executable(const std::string &cmd, const std::vector<std::string> &argv);

  std::string GetCmd() const;

  std::vector<std::string> GetArgv() const;

private:
  std::string cmd_m;
  std::vector<std::string> argv_m;
};

}
