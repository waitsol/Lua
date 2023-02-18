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
class Inter
{
public:
    int val;
    Inter(int k) : val(k) {}
    bool operator==(Inter &rhs)
    {
        return val == rhs.val;
    }
    static char lua_p;
};
char Inter::lua_p = 3;
class Inter_create_count
{
public:
    int c;
};
class Inter_pool
{
public:
    Inter *get(int n)
    {
        // 调用upvalue
        printf("Inter_pool get %d\n", n);
        return nullptr;
    }
    void set(int n)
    {
        printf("Inter_pool set %d\n", n);
    }
};
int create_Inter(lua_State *L)
{
    // 不写错误判断 只写 逻辑  看怎么用
    // 获取上值
    Inter_pool *ip = (Inter_pool *)lua_touserdata(L, lua_upvalueindex(1));
    Inter_create_count *icc = (Inter_create_count *)lua_touserdata(L, lua_upvalueindex(2));
    icc->c++;
    log(icc->c);
    // 只是测试 理解上值如何使用
    ip->get(lua_tointeger(L, -1));
    ip->set(lua_tointeger(L, -1));
    void *p = lua_newuserdata(L, sizeof(Inter));

    new (p) Inter(lua_tointeger(L, -2));
    // 获取p的元表
    lua_rawgetp(L, LUA_REGISTRYINDEX, &Inter::lua_p);
    lua_setmetatable(L, -2);
    return 1;
}
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
int equal_Inter(lua_State *L)
{
    // 不写错误判断 只写 逻辑  看怎么用
    Inter *a = (Inter *)lua_touserdata(L, -1);
    Inter *b = (Inter *)lua_touserdata(L, -2);
    lua_pushboolean(L, *a == *b);
    return 1;
}
// 必须加这个 如果是c++编译 这里写测试就没那么规范 测试是c++
extern "C"
{
    int // lua 中 require class.core
    luaopen_class_core(lua_State *L)
    {
        luaL_Reg l[] = {
            {"create_inter", create_Inter},

            {NULL, NULL},
        };

        // 先创建class的元表
        lua_newtable(L);
        // 元表的index字段
        lua_pushstring(L, "__index"); // mt,idx
        // index字段对应的表
        lua_newtable(L); // mt,idx,itxt
        // 创建表当中的函数
        lua_pushstring(L, "equal");
        //=lua_pushcclosure 因为上值数量的0
        lua_pushcclosure(L, equal_Inter, 0);
        lua_rawset(L, -3); // mt,idx,itxt
        lua_rawset(L, -3); // mt
        lua_rawsetp(L, LUA_REGISTRYINDEX, &Inter::lua_p);

        // // 设置_g create函数 上一章的东西 这里我们用下面的代替
        // lua_getglobal(L, "_G");
        // // 设置upvalue
        // lua_pushstring(L, "create_inter");
        // lua_newuserdata(L, sizeof(Inter_pool));
        // lua_newuserdata(L, sizeof(Inter_create_count));
        // lua_pushcclosure(L, create_Inter, 2);
        // lua_rawset(L, -3);
        // lua_pop(L, 2); // 弹出g表和mt表
        lua_createtable(L, 0, sizeof(l) / sizeof(l[0]) - 1);
        // 上值
        lua_newuserdata(L, sizeof(Inter_pool));
        void *p = lua_newuserdata(L, sizeof(Inter_create_count));

        memset(p, 0, sizeof(Inter_create_count));
        luaL_setfuncs(L, l, 2);

        return 1;
    }
}