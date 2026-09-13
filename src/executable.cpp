#include "executable.hpp"

#include <stdexcept>
#include <string>
#include <vector>

#include "utils.hpp"

namespace shell {

ExecutableContext::ExecutableContext(const std::string& cmd) {
  this->cmd_m = cmd;
}

ExecutableContext::ExecutableContext(const std::string& cmd, const std::vector<std::string>& argv) {
  this->cmd_m = cmd;
  this->argv_m = argv;
}

std::string ExecutableContext::GetCmd() const {
  return this->cmd_m;
}

std::vector<std::string> ExecutableContext::GetArgv() const {
  return this->argv_m;
}

utils::LoopDecision Executable::Run(const ExecutableContext& context) const {
  throw std::logic_error{"Unreachable"};
}

}  // namespace shell
