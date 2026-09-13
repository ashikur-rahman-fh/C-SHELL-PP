#pragma once

#include <memory>
#include <string>
#include <vector>

#include "executable.hpp"

namespace builtin {
enum BuiltinType {
  ExitCmd,
  EchoCmd,
  TypeCmd,
};

const std::vector<std::pair<std::string, BuiltinType>> builtins = {
    {"exit", BuiltinType::ExitCmd},
    {"echo", BuiltinType::EchoCmd},
    {"type", BuiltinType::TypeCmd},
};

bool IsBuiltIn(std::shared_ptr<shell::IExecutable> exe);

bool IsBuiltIn(const std::string& cmd);

BuiltinType GetBuiltinType(const std::string& cmd);

BuiltinType GetBuiltinType(std::shared_ptr<shell::IExecutable> exe);
}  // namespace builtin
