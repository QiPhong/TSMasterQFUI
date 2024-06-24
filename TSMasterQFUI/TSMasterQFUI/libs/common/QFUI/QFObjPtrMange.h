#ifndef __QFOBJPTRMANGE_H
#define __QFOBJPTRMANGE_H
#include <functional>
/*
*#####################################################################################管理模板
*__ObjPtrMangement
*指针管理类，主要使用解决单例模式不会析构
*创建一个全局变量__ObjPtrMangement<claseNmae> g_var
*再g_var.setMange(类指针,&要执行的成员函数)，在g_var析构时回执行
*#####################################################################################
*/
template<typename T, typename... Args>
class __ObjPtrMangement
{
    T* __obj;
    void (T::*__func)(Args...);
    std::tuple<Args...> __args;
    public:
    void setMange(T* obj, void (T::*func)(Args...), Args... args){
        __obj=obj;__func=func;__args=std::make_tuple(args...);
    }
    
    ~__ObjPtrMangement(){
        if(NULL !=__obj){
            __callFunc(__obj, __func, __args);
            
        }

    }

    private:
    template<typename U, typename... UArgs>
    void __callFunc(U* obj, void (U::*func)(UArgs...), std::tuple<UArgs...>& tuple) {
        __callFunc(obj, func, tuple, std::index_sequence_for<UArgs...>());
    }

    template<typename U, typename... UArgs, size_t... Indices>
    void __callFunc(U* obj, void (U::*func)(UArgs...), std::tuple<UArgs...>& tuple, std::index_sequence<Indices...>) {
        (obj->*func)(std::get<Indices>(tuple)...);
    }


};




































#endif