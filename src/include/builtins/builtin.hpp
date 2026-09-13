#pragma once

#include "executable.hpp"
#include <string>
#include <vector>

namespace  builtin {
  const std::vector<std::string>builtins = {"exit"};

  bool IsBuiltIn(const shell::Executable &exe);
}
