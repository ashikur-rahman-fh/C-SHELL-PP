#include "builtins/builtin.hpp"

#include <algorithm>

#include "executable.hpp"

namespace builtin {
bool IsBuiltIn(const shell::ExecutableContext& context) {
  return std::find_if(builtins.begin(), builtins.end(), [&](const auto& val) {
           return val.first == context.GetCmd();
         }) != builtins.end();
}

bool IsBuiltIn(const std::string& cmd) {
  return std::find_if(builtins.begin(), builtins.end(),
                      [&](const auto& val) { return val.first == cmd; }) != builtins.end();
}

BuiltinType GetBuiltinType(const std::string& cmd) {
  return std::find_if(builtins.begin(), builtins.end(),
                      [&](const auto& val) { return val.first == cmd; })
      ->second;
}

BuiltinType GetBuiltinType(const shell::ExecutableContext& context) {
  return std::find_if(builtins.begin(), builtins.end(),
                      [&](const auto& val) { return val.first == context.GetCmd(); })
      ->second;
}
}  // namespace builtin
