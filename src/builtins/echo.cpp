#include "echo.hpp"

#include <iostream>
#include <ranges>
#include <string>

#include "executable.hpp"
#include "utils.hpp"

namespace builtin {

utils::LoopDecision Echo::Run(const shell::ExecutableContext& context) const {
  const std::string delimiter = " ";
  const std::string result =
      context.GetArgv() | std::views::join_with(std::string(" ")) | std::ranges::to<std::string>();
  std::cout << result << std::endl;
  return utils::LoopDecision::Continue;
}

}  // namespace builtin
