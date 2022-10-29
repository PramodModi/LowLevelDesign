#include"IEvictionPolicy.h"
#include"DoublyLinkedList.cpp"
#include<unordered_map>
using namespace std;

class LRUPolicy: public IEvictionPolicy{
    private:
        DoublyLinkedList *dll;
        unordered_map<string, Node*> map;
    public:
        ~LRUPolicy(){
            if(dll != NULL)
                delete dll;
        }
        LRUPolicy(){
            dll = new DoublyLinkedList();
        }
        void keyAccessed(string key){
            if(map.find(key) == map.end()){
                map[key] = new Node(key);
                dll->addNode(map[key]);
            }
            else{
                dll->seHead(map[key]);
            }
        }
        string evict(){
            string key = dll->tail->key;
            dll->removeNode(dll->tail);
            map.erase(key);
            return key;
        }

};