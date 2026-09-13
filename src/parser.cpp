#include "parser.hpp"

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <vector>

#include "executable.hpp"

namespace parser {
std::vector<std::string> Split(std::string_view input, std::string_view delimiter) {
  std::vector<std::string> result;

  size_t start = input.find_first_not_of(delimiter);
  while (start != std::string::npos) {
    size_t end = input.find_first_of(delimiter, start);

    if (end == std::string::npos) {
      result.emplace_back(input.substr(start));
      break;
    }

    result.emplace_back(input.substr(start, end - start));
    start = input.find_first_not_of(delimiter, end);
  }

  return result;
}

std::shared_ptr<shell::IExecutable> ParseExecutable(const std::string& input) {
  auto tokens = Split(input);
  return std::make_shared<shell::Executable>(
      tokens.front(), std::vector<std::string>(tokens.begin() + 1, tokens.end()));
}

std::vector<std::string> Parse(const std::string& input) {
  return Split(input);
}
}  // namespace parser
