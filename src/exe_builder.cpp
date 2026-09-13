#include "exe_builder.hpp"
#include "builtin.hpp"
#include "echo.hpp"
#include "executable.hpp"
#include <memory>
#include <stdexcept>
#include <vector>
#include "builtins/exit.hpp"

namespace shell {

std::shared_ptr<IExecutable> ExeBuilder::build(std::vector<std::string> &inputTokens) {
  const std::string cmd = inputTokens.front();
  const std::vector<std::string> argv = std::vector<std::string> (inputTokens.begin() + 1, inputTokens.end());

  if (builtin::IsBuiltIn(cmd)) {
    switch (builtin::GetBuiltinType(cmd)) {
      case builtin::BuiltinType::ExitCmd:
        return std::make_shared<builtin::Exit> (cmd, argv);
      case builtin::BuiltinType::EchoCmd:
        return std::make_shared<builtin::Echo> (cmd, argv);
      default:
        throw std::logic_error {"Invalid builtin type"};
    }
  }

  return std::make_shared<Executable> (cmd, argv);
}

}
