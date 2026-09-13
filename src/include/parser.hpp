#pragma once

#include <memory>
#include <string>
#include <vector>

#include "executable.hpp"

namespace parser {

std::shared_ptr<shell::IExecutable> ParseExecutable(const std::string& input);

std::vector<std::string> Split(std::string_view input, std::string_view delimiter = " ");

std::vector<std::string> Parse(const std::string& input);
}  // namespace parser
