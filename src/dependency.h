#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <optional>

struct Dependency{
    std::string name;
    std::optional<std::string> remote_url;
    std::optional<std::string> lib_file_name;

    std::vector<std::string> include_dir_paths;
    std::vector<std::string> lib_dir_paths;

    bool local;

    Dependency(std::string url);

    bool init_dependency();
};