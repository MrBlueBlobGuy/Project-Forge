language = "C++"

dependencies = {}
dependencies["lua"] = "https://github.com/lua/lua.git"
dependencies["spdlog"] = "https://github.com/gabime/spdlog.git"

configs = {"Debug", "Release"}

if config("Debug") then
    defines = {"PFDEBUG"}
    symbols = "On"
else if config("Release") then
    defines = {"PFRELEASE"}
    optimize = "On"
end