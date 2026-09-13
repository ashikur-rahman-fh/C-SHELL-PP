#include "echo.hpp"
#include "utils.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <numeric>



namespace builtin {
  Echo::Echo(const std::string &cmd) {
    this -> cmd_m = cmd;
  }

  Echo::Echo(const std::string &cmd, const std::vector<std::string> &argv) {
    this -> cmd_m = cmd;
    this -> argv_m = argv;
  }

  std::string Echo::GetCmd() const {
    return this -> cmd_m;
  }

  std::vector<std::string> Echo::GetArgv() const {
    return this -> argv_m;
  }

  utils::LoopDecision Echo::Run() const {
    const std::string delimiter = " ";
    std::string result = std::accumulate(
      std::next(argv_m.begin()), argv_m.end(), argv_m[0],
      [&delimiter](const std::string& a, const std::string& b) {
          return a + delimiter + b;
      }
    );
    std::cout << result << std::endl;
    return utils::LoopDecision::Continue;
  }

}
