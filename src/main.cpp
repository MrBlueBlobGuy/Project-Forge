#include <iostream>
#include <string>

extern "C"{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

bool CheckLua(lua_State *L, int r){
    if (r != LUA_OK){
        std::string error_msg = lua_tostring(L, -1);
        std::cerr << error_msg << std::endl;
        return false;
    }
    return true;
}

int main(){

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    int r = luaL_dofile(L, "defaults/c++.lua");

    

    std::cin.get();
    lua_close(L);
}