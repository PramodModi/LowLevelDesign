# pragma once
#include<iostream>
#include<string>
using namespace std;

class IEvictionPolicy{
    public:
    virtual void keyAccessed(string key) = 0;
    virtual string evict() = 0;
    virtual ~IEvictionPolicy(){}
};