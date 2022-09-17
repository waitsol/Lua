#include "iostream"
#include "tolua.h"
#include "lua.h"
#include "fstream"
using namespace std;
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}
extern int tolua_Student_open(lua_State* tolua_S);
int main()
{
    char c[]={0xAA};
    cout<<c<<endl;
    lua_State *L = luaL_newstate(); //新建lua解释器
	luaL_openlibs(L); //载入lua所有函数库
   
    //必须掉这一行 不然没效果，
    tolua_Student_open(L);
#if 0
    luaL_dofile(L, "./test.lua");
#else
    char buf[2048*100]={0};
    ifstream ifs("./test.lua",ios::binary);
    ifs.read(buf,2048*100);
    cout<<ifs.gcount()<<endl;
    int xx=luaL_loadbuffer(L,buf,ifs.gcount(),"zzz");
    cout<<"xx="<<xx<<endl;
    //不掉用就不行
    lua_pcall(L, 0, 0, 0);
    for(int i=0;i<xx;i++)
    {
        auto ret = lua_tostring(L, -1); //获取栈顶元素（结果）
        cout<<ret<<endl;
    }
#endif
    lua_getglobal(L, "Run");
    int x=lua_pcall(L, 0, 0, 0); //调用函数，2个参数，1个返回值 参数4如果为真值代表错误处理函数所在的函数栈下标
	for(int i=0;i<x;i++)
    {
        auto ret = lua_tostring(L, -1); //获取栈顶元素（结果）
        cout<<ret<<endl;
    }
	lua_close(L);

    return 0;
}
//g++ main.cpp  lua_student.cpp  -I/usr/include/lua5.2 -llua5.2 -ltolua Student.cpp