# pragma once
#include<iostream>
#include <string>
using namespace std;

class IStorage{
    public:
        virtual void add(string key, int value) = 0;
        virtual void remove(string key)= 0;
        virtual int get(string key)= 0;
        virtual ~IStorage(){}
};