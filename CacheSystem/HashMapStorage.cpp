#include<iostream>
#include<unordered_map>
#include<exception>
#include "IStorage.h"
using namespace std;

class HashMapStorage: public IStorage{
    private:
        unordered_map<string, int> map;
    public:
        HashMapStorage(){
            map.clear();
        }
        virtual ~HashMapStorage(){
            map.clear();
        }
        void add(string key, int value){
            map[key] = value;
        }

        void remove(string key){
            map.erase(key);
        }
        int get(string key){
            if(map.find(key) == map.end()){
                throw exception();
            }
            else{
                return map[key];
            }

        }

};