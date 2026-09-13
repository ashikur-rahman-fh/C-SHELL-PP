
#include "exit.hpp"
#include "utils.hpp"
#include <string>
#include <vector>

namespace builtin {
  Exit::Exit(const std::string &cmd) {
    this -> cmd_m = cmd;
  }

  Exit::Exit(const std::string &cmd, const std::vector<std::string> &argv) {
    this -> cmd_m = cmd;
    this -> argv_m = argv;
  }

  std::string Exit::GetCmd() const {
    return this -> cmd_m;
  }

  std::vector<std::string> Exit::GetArgv() const {
    return this -> argv_m;
  }

  utils::LoopDecision Exit::Run() const {
    return utils::LoopDecision::Break;
  }

}
