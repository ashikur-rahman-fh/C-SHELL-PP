#include "repl.hpp"

#include <iostream>
#include <string>

#include "command_executor.hpp"
#include "exe_builder.hpp"
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
      std::vector<std::string> inputTokens = parser::Parse(userInput);
      utils::LoopDecision decision =
          shell::CommandExecutor(shell::ExeBuilder().build(inputTokens)).Execute();
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

void Repl::setPromptSymbol(const std::string& promptSymbol) {
  this->promptSymbol_m = promptSymbol;
}

}  // namespace repl
