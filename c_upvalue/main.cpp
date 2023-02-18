#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
#include "zlk_lua.h"
static int
traceback(lua_State *L)
{
    const char *msg = lua_tostring(L, 1);
    if (msg)
    {
        log(msg);
        luaL_traceback(L, L, msg, 1);
    }
    else
    {
        lua_pushliteral(L, "(no error message)");
    }
    return 1;
}
int main()
{

    lua_State *L = luaL_newstate(); // 新建lua解释器
    luaL_openlibs(L);               // 载入lua所有函数库

    char buf[2048 * 100] = {0};
    ifstream ifs("./test.lua", ios::binary);
    ifs.read(buf, 2048 * 100);
    int xx = luaL_loadbufferx(L, buf, ifs.gcount(), "upl", "t");

    lua_getglobal(L, "_G"); // trunk,_G,
    lua_newtable(L);        // trunk,_G,table
    {
        // 这里给table设置元表
        lua_newtable(L); // t,g,t,mt

        lua_pushstring(L, "__index"); // t,g,t,mt,index
        lua_getglobal(L, "_G");       // t,g,t,mt,index,g

        // 设置mt表index属性
        lua_rawset(L, -3); // t,g,t,mt
        log(lua_setmetatable(L, -2));
    }

    lua_pushstring(L, "uv"); // trunk,_G,table,uv
    lua_pushvalue(L, -2);    // trunk,_G,table,uv,table
    lua_rawset(L, -4);       // trunk,_G,table
    log(lua_setupvalue(L, -3, 1));
    lua_pop(L, 1);
    lua_pushnumber(L, 1);
    zlk_lua_top_type(L);
    lua_pcall(L, 1, 0, 0);
    zlk_lua_top_type(L);
    log(lua_tostring(L, -1));
    lua_close(L);

    return 0;
}
// g++ main.cpp  lua_student.cpp  -I/usr/include/lua5.2 -llua5.2 -ltolua Student.cpp