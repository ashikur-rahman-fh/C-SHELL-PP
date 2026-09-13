
#include "type.hpp"

#include <format>
#include <iostream>
#include <ranges>

#include "builtin.hpp"
#include "executable.hpp"
#include "path_helper.hpp"
#include "utils.hpp"

namespace builtin {

utils::LoopDecision Type::Run(const shell::ExecutableContext& context) const {
  const std::string argv =
      context.GetArgv() | std::views::join_with(std::string(" ")) | std::ranges::to<std::string>();

  if (IsBuiltIn(argv)) {
    std::cout << std::format("{} is a shell builtin", argv) << std::endl;
    return utils::LoopDecision::Continue;
  }

  std::filesystem::path localExePath = path_helper::GetLocalExecutablePath(argv);
  if (!localExePath.empty()) {
    std::cout << std::format("{} is {}", argv, localExePath.string()) << std::endl;
    return utils::LoopDecision::Continue;
  }

  throw utils::ShellError(std::format("{}: not found", argv), utils::LoopDecision::Continue);
}

}  // namespace builtin
