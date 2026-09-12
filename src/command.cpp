#include "command.hpp"
#include "utils.hpp"
#include "format"


namespace shell {
  Command::Command(const std::string &text) {
    this -> text_m = text;
  }

  std::string Command::getText() const {
    return this -> text_m;
  }

  utils::LoopDecision Command::Execute() {
    throw utils::ShellError(std::format("{}: command not found", this -> text_m),
      utils::LoopDecision::Continue);
  }

}
