#include "dependency.h"
#include <filesystem>

std::string get_include_dir_path_cpp(std::string path){
    // The include directory will be got using the following logic:
    // 1. If there is a directory named "include" in the root of the dependency, then that is the include directory.
    // 2. If there is no directory named "include" in the root of the dependency But, there is a directory named "src" in the root of the dependency, then that is the include directory.
    // 3. If there is no directory named "include" or "src" in the root of the dependency, then the root of the dependency is the include directory.

    std::string include_dir_path = path + "/include";
    if(std::filesystem::exists(include_dir_path)){
        return include_dir_path;
    }

    include_dir_path = path + "/src";
    if(std::filesystem::exists(include_dir_path)){
        return include_dir_path;
    }

    return path;
}


Dependency::Dependency(std::string url){
    name = url;
    remote_url = url;
    lib_file_name = std::nullopt;
    local = false;
}

bool Dependency::init_dependency(){
    std::cout << "Initializing dependency: " << name << std::endl;
    std::string command = "git submodule add " + remote_url.value() + "thirdparty/" + name;
    system(command.c_str());
    

    return true;
}