#include "path_helper.hpp"

#include <filesystem>
#include <ranges>
#include <stdexcept>
#include <string_view>
#include <vector>

namespace path_helper {
constexpr char path_delimiter = ':';

std::string GetPath() {
  const char* path = std::getenv("PATH");
  if (path == nullptr) {
    throw std::runtime_error("PATH variable is not set.");
  }

  return path;
}

std::vector<std::string> GetAllSubpath(const std::string_view path) {
  std::vector<std::string> result = {};

  for (auto&& subPath : path | std::views::split(path_delimiter)) {
    result.emplace_back(std::string_view(subPath));
  }

  return result;
}

std::vector<std::filesystem::path> GetValidDirectoriesInPath(const std::string_view path) {
  std::vector<std::string> directories = GetAllSubpath(path);

  return directories | std::views::filter([](const std::filesystem::path& probDir) {
           return std::filesystem::is_directory(probDir);
         }) |
         std::ranges::to<std::vector<std::filesystem::path>>();
}

bool IsExecutableFile(const std::filesystem::directory_entry& name) {
  if (!name.is_regular_file()) {
    return false;
  }

  const std::filesystem::perms permission = name.status().permissions();
  return (permission & (std::filesystem::perms::owner_exec | std::filesystem::perms::group_exec |
                        std::filesystem::perms::others_exec)) != std::filesystem::perms::none;
}

std::filesystem::path FindExecutableInDirectory(const std::filesystem::path& dir,
                                                std::string_view exe) {
  if (!std::filesystem::is_directory(dir)) {
    return "";
  }
  for (const auto& entry : std::filesystem::directory_iterator(
           dir, std::filesystem::directory_options::skip_permission_denied)) {
    if (entry.path().filename().string() == exe && IsExecutableFile(entry)) {
      return entry.path();
    }
  }
  return {};
}

std::filesystem::path GetLocalExecutablePath(std::string_view exe) {
  const std::string path = GetPath();
  auto directories = GetValidDirectoriesInPath(path);
  for (const auto& dir : directories) {
    const std::filesystem::path exePath = FindExecutableInDirectory(dir, exe);
    if (!exePath.empty()) {
      return exePath;
    }
  }
  return {};
}

}  // namespace path_helper
