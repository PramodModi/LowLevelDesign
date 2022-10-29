# pragma once
#include<iostream>
#include <string>
using namespace std;
template<class T1, class T2>
class IStorage{
    public:
        virtual void add(T1 key, T2 value) = 0;
        virtual void remove(T1 key)= 0;
        virtual T2 get(T1 key)= 0;
        virtual ~IStorage(){}
};