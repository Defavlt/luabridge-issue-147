#include <iostream>
#include <string>
#include <lua/lua.hpp>
#include <LuaBridge/LuaBridge.h>

#include "common.h"
#include "table.h"

using namespace luabridge;

int main(int, char **)
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);

    typedef property<Table0> prop0;

    getGlobalNamespace(L)
        // Table0 
        .beginClass<Table0>("Tbl0")
            .addProperty("m_str"
                , &prop0::get<std::string, &Table0::m_str>
                , &prop0::set<std::string, &Table0::m_str>)
            .addProperty("m_int"
                , &prop0::get<int, &Table0::m_int>
                , &prop0::set<int, &Table0::m_int>)
            .addProperty("m_bool"
                , &prop0::get<bool, &Table0::m_bool>
                , &prop0::set<bool, &Table0::m_bool>)
        .endClass()

        .beginClass<Table1>("Tbl1")
            .addProperty("nested"
                , &Table1::get)
        .endClass();

    Table1 tbl1;

    luabridge::push<Table1 *>(L, &tbl1);
    lua_setglobal(L, "tbl1");

    std::string cmd ("tbl1.nested.m_int = 5");

    while(1) {
        if (luaL_dostring(L, cmd.c_str())) {
            int nargs = lua_gettop(L);

            for (int i = 1; i <= nargs; ++i)
                std::cout << lua_tolstring(L, i, NULL);

            std::cout << std::endl;
        }
        
        std::cout << "> ";
        std::getline(std::cin, cmd);
    }
}
