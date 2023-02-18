#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;
//lua库是c编译的没加 __cplusplus
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
#include "zlk_lua.h"
#include "zlk_log.h"
int main()
{
    zlk_log::getInstance().init("",1,1);
    lua_State *L = luaL_newstate(); //新建lua解释器
	luaL_openlibs(L); //载入lua所有函数库
   
#if 0
    //直接运行脚本文件
    //   luaL_dofile(L, "./test.lua");     (luaL_loadfile(L, filename) || lua_pcall(L, 0, LUA_MULTRET, 0))
    // 只是加载
    luaL_loadfile(L, "./test.lua");
#else
    char buf[2048*100]={0};
    ifstream ifs("./test.lua",ios::binary);
    ifs.read(buf,2048*100);
    {

        auto ret = luaL_loadbuffer(L, buf, ifs.gcount(), "cload_lua");
        log(ret);
    }

    log(zlk_lua_t2s(lua_getglobal(L, "g_zlk_table")));
    lua_pop(L,1);//因为没有加载 所以获取不到
    zlk_lua_top_type(L);
    //调用函数 加载
    lua_pcall(L, 0, 1, 0);
    //重新加载就可以
    log(zlk_lua_t2s(lua_getglobal(L, "g_zlk_table")));
    log(zlk_lua_t2s(lua_getglobal(L, "test_table")));
    zlk_lua_top_type(L);
#endif

    log(zlk_lua_t2s(lua_getglobal(L, "Zlk_print")));
    if (lua_type(L, -1) != LUA_TFUNCTION)
    {
        printf("can not find function: parseData.\n");
        lua_close(L);
        return 1;
    }
    log(zlk_lua_t2s(lua_getglobal(L, "g_zlk_table")));
    //将-1这个地方的表值 one推送到栈顶
    log(lua_getfield(L, -1, "one"));
    //-2出栈
    
    lua_remove(L,-2);
    if (lua_pcall(L, 1, 1, 0)!=0)
    {   
        if(lua_isstring(L,-1))
        {
            printf("pcall failed = %s\n",lua_tostring(L,-1));
        }
    }

    log(zlk_lua_t2s(lua_getglobal(L, "Zlk_print_G")));
    if (lua_type(L, -1) != LUA_TFUNCTION)
    {
        printf("can not find function: parseData.\n");
        lua_close(L);
        return 1;
    }
    lua_pushstring(L, "cload_lua");

        lua_remove(L, -2);
    if (lua_pcall(L, 1, 1, 0) != 0)
    {
        if (lua_isstring(L, -1))
        {
            printf("pcall failed = %s\n", lua_tostring(L, -1));
        }
    }

    lua_close(L);
    DBG("aa");
    return 0;
}
//g++ main.cpp  lua_student.cpp  -I/usr/include/lua5.2 -llua5.2 -ltolua Student.cpp