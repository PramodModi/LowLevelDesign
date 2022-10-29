#include<iostream>
#include<unordered_map>
#include "IStorage.h"
#include<exception>
using namespace std;
template<class T1, class T2>
class HashMapStorage: public IStorage<T1, T2>{
    private:
        unordered_map<T1, T2> map;
    public:
        HashMapStorage(){
            map.clear();
        }
        virtual ~HashMapStorage(){
            map.clear();
        }
        void add(T1 key, T2 value){
            map[key] = value;
        }

        void remove(T1 key){
            map.erase(key);
        }
        T2 get(T1 key){
            if(map.find(key) == map.end()){
                throw exception();
            }
            else{
                return map[key];
            }

        }

};