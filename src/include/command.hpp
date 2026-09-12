#pragma once

#include <string>
#include "utils.hpp"

namespace shell {

class Command {
public:
  Command() = delete;

  Command(const std::string &text);

  std::string getText() const;

  utils::LoopDecision Execute();

private:
  std::string text_m;
};

} // shell ends
