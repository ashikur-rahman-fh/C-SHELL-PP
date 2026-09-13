#pragma once

#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

namespace path_helper {

std::string GetPath();

std::vector<std::string> GetAllSubpath(const std::string_view path);

std::vector<std::filesystem::path> GetValidDirectoriesInPath(const std::string_view path);

bool IsExecutableFile(const std::filesystem::directory_entry& name);

std::filesystem::path FindExecutableInDirectory(const std::filesystem::path& dir,
                                                std::string_view exe);

std::filesystem::path GetLocalExecutablePath(std::string_view exe);

}  // namespace path_helper
