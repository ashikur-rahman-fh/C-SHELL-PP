#include "builtins/builtin.hpp"
#include <algorithm>

namespace builtin {

  bool IsBuiltIn(const shell::Executable &exe) {
    return std::find(builtins.begin(), builtins.end(), exe.GetCmd()) != builtins.end();
  }
}
