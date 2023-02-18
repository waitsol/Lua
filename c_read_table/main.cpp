#include "iostream"
#include "fstream"
#include "string.h"
using namespace std;

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
#include "zlk_lua.h"

/* 遍历一维表 */
void table_traverse(lua_State *L)
{

    lua_pushnil(L); /* table 里第一对 key-value 的前面没有数据，所以先用 lua_pushnil() 压入一个 nil 充当初始 key */
  //  printluaTopType(L);
    while (lua_next(L, -2))
    {
        // std::cout << "---Loop start: Stack size = " << lua_gettop(L) << std::endl;
     //   printluaTopType(L);
        /* 输出key */
        if (lua_isnumber(L, -2))
        {
            std::cout << "key = " << lua_tonumber(L, -2) << ", ";
        }
        else if (lua_isstring(L, -2))
        {
            std::cout << "key = " << lua_tostring(L, -2) << ", ";
        }
        else
        {
            std::cout << "Error key type!" << std::endl;
        }

        /* 输出value */
        if (lua_isnumber(L, -1))
        {
            std::cout << "value = " << lua_tonumber(L, -1) << std::endl;
            lua_pop(L, 1);
        }
        else if (lua_isstring(L, -1))
        {
            std::cout << "value = " << lua_tostring(L, -1) << std::endl;
            lua_pop(L, 1);
        }
        else
        {
          //  printluaTopType(L);
            table_traverse(L);
        }
      //  printluaTopType(L);

        /* 弹出一个元素，即当前的value */
     
        // std::cout << "---Loop end: Stack size = " << lua_gettop(L) << std::endl;
    }

    lua_pop(L, 1);
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
int main()
{

    lua_State *L = luaL_newstate(); //新建lua解释器
	luaL_openlibs(L); //载入lua所有函数库
   
#if 0
    luaL_dofile(L, "./test.lua");
#else
    char buf[2048*100]={0};
    ifstream ifs("./test.lua",ios::binary);
    ifs.read(buf,2048*100);
    cout<<ifs.gcount()<<endl;
    int xx=luaL_loadbufferx(L,buf,ifs.gcount(),"zzz","t");
  
    //不掉用就不行
    cout<<lua_type(L, -1)<<endl;
    lua_pushstring(L,"aa");
    lua_pcall(L, 1, 1, 0);
    cout << lua_type(L, -2) << endl;
    table_traverse(L);
#endif
    lua_getglobal(L, "Run");
    
    if (lua_type(L, -1) != LUA_TFUNCTION)
    {
        printf("can not find function: parseData.\n");
        lua_close(L);
        return 1;
    }
    lua_pushnumber(L,3);
    int x=lua_pcall(L, 1, 1, 0); //调用函数，0个参数，1个返回值 参数4如果为真值代表错误处理函数所在的函数栈下标
    
   
    if(x==LUA_OK)
    {
        auto ret=lua_tonumber(L,-1);
        log(ret);
        lua_pop(L, 1);
    }
    
    struct Net{
        int addr;
        int port;
    };
    Net n;
    log(lua_gettop(L));

    lua_pushcfunction(L, traceback);
    lua_getglobal(L, "Pc");
    lua_pushlightuserdata(L,&n);
    x = lua_pcall(L, 1, 0, 1); // 调用函数，1个参数，0个返回值 参数4如果为真值代表错误处理函数所在的函数栈下标
    log(x);
    log(lua_type(L, -1));
    lua_close(L);
    
    return 0;
}
//g++ main.cpp  lua_student.cpp  -I/usr/include/lua5.2 -llua5.2 -ltolua Student.cpp