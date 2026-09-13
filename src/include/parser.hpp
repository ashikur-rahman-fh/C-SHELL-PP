#pragma once

#include <string>
#include <vector>

#include "executable.hpp"

namespace parser {

shell::Executable ParseExecutable(const std::string &input);

std::vector<std::string> Split(std::string_view input, std::string_view delimiter = " ");

}
