#include "echo.hpp"

#include <iostream>
#include <ranges>
#include <string>
#include <vector>

#include "utils.hpp"

namespace builtin {
Echo::Echo(const std::string& cmd) {
  this->cmd_m = cmd;
}

Echo::Echo(const std::string& cmd, const std::vector<std::string>& argv) {
  this->cmd_m = cmd;
  this->argv_m = argv;
}

std::string Echo::GetCmd() const {
  return this->cmd_m;
}

std::vector<std::string> Echo::GetArgv() const {
  return this->argv_m;
}

utils::LoopDecision Echo::Run() const {
  const std::string delimiter = " ";
  const std::string result =
      argv_m | std::views::join_with(std::string(" ")) | std::ranges::to<std::string>();
  std::cout << result << std::endl;
  return utils::LoopDecision::Continue;
}

}  // namespace builtin
