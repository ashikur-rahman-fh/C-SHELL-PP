#include <iostream>
#include <string>

#include "repl.hpp"
#include "command_executor.hpp"
#include "executable.hpp"
#include "parser.hpp"
#include "utils.hpp"

namespace repl {

Repl::Repl() {
  promptSymbol_m = "$";
}

void Repl::Run() const {
  while (true) {
  std::cout << promptSymbol_m << " ";
    std::string userInput;
    std::getline(std::cin, userInput);

    try {
      const shell::Executable exe = parser::ParseExecutable(userInput);
      utils::LoopDecision decision = shell::CommandExecutor(exe).Execute();
      if (decision == utils::LoopDecision::Continue) {
        continue;
      } else if (decision == utils::LoopDecision::Break) {
        break;
      }
    } catch (utils::ShellError error) {
      std::cout << error.what() << std::endl;
      if (error.getLoopDecision() == utils::LoopDecision::Continue) {
        continue;
      } else if (error.getLoopDecision() == utils::LoopDecision::Break) {
        break;
      }
    }
  }
}

std::string Repl::getPromptSymbol() const {
  return promptSymbol_m;
}

void Repl::setPromptSymbol(const std::string &promptSymbol) {
  this->promptSymbol_m = promptSymbol;
}

}
