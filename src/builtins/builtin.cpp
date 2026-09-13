#include "builtins/builtin.hpp"

#include <algorithm>
#include <memory>

#include "executable.hpp"

namespace builtin {
bool IsBuiltIn(std::shared_ptr<shell::IExecutable> exe) {
  return std::find_if(builtins.begin(), builtins.end(), [&](const auto& val) {
           return val.first == exe->GetCmd();
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

BuiltinType GetBuiltinType(std::shared_ptr<shell::IExecutable> exe) {
  return std::find_if(builtins.begin(), builtins.end(),
                      [&](const auto& val) { return val.first == exe->GetCmd(); })
      ->second;
}
}  // namespace builtin
