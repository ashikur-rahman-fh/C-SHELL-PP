#include "executable.hpp"

#include <stdexcept>
#include <string>
#include <vector>

#include "utils.hpp"

namespace shell {
Executable::Executable(const std::string& cmd) {
  this->cmd_m = cmd;
}

Executable::Executable(const std::string& cmd, const std::vector<std::string>& argv) {
  this->cmd_m = cmd;
  this->argv_m = argv;
}

std::string Executable::GetCmd() const {
  return this->cmd_m;
}

std::vector<std::string> Executable::GetArgv() const {
  return this->argv_m;
}

utils::LoopDecision Executable::Run() const {
  throw std::logic_error{"Unreachable"};
}

}  // namespace shell
