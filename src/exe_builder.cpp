#include "exe_builder.hpp"

#include <memory>
#include <stdexcept>
#include <vector>

#include "builtin.hpp"
#include "builtins/exit.hpp"
#include "echo.hpp"
#include "executable.hpp"
#include "type.hpp"

namespace shell {

std::shared_ptr<IExecutable> ExeBuilder::build(std::vector<std::string>& inputTokens) {
  const std::string cmd = inputTokens.front();
  const std::vector<std::string> argv =
      std::vector<std::string>(inputTokens.begin() + 1, inputTokens.end());

  if (builtin::IsBuiltIn(cmd)) {
    switch (builtin::GetBuiltinType(cmd)) {
      case builtin::BuiltinType::ExitCmd:
        return std::make_shared<builtin::Exit>();
      case builtin::BuiltinType::EchoCmd:
        return std::make_shared<builtin::Echo>();
      default:
        throw std::logic_error{"Invalid builtin type"};
    }
  }

  return std::make_shared<Executable>();
}

std::shared_ptr<IExecutable> ExeBuilder::build(const ExecutableContext& context) {
  const std::string cmd = context.GetCmd();

  if (builtin::IsBuiltIn(cmd)) {
    switch (builtin::GetBuiltinType(cmd)) {
      case builtin::BuiltinType::ExitCmd:
        return std::make_shared<builtin::Exit>();
      case builtin::BuiltinType::EchoCmd:
        return std::make_shared<builtin::Echo>();
      case builtin::BuiltinType::TypeCmd:
        return std::make_shared<builtin::Type>();
      default:
        throw std::logic_error{"Invalid builtin type."};
    }
  }

  return std::make_shared<Executable>();
}

}  // namespace shell
