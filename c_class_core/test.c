
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
LUAMOD_API int // lua 中 require class.core
luaopen_testlib(lua_State *L)
{

    return 1;
}