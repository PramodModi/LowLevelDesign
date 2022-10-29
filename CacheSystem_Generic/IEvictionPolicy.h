# pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T1>
class IEvictionPolicy{
    public:
    virtual void keyAccessed(T1 key) = 0;
    virtual string evict() = 0;
    virtual ~IEvictionPolicy(){}
};