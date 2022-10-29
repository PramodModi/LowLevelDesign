#include"IEvictionPolicy.h"
#include"DoublyLinkedList.cpp"
#include<unordered_map>
using namespace std;
template<class T1>
class LRUPolicy: public IEvictionPolicy<T1>{
    private:
        DoublyLinkedList<T1> *dll;
        unordered_map<T1, Node<T1> *> map;
    public:
        ~LRUPolicy(){
            if(dll != NULL)
                delete dll;
        }
        LRUPolicy(){
            dll = new DoublyLinkedList<T1>();
        }
        void keyAccessed(T1 key){
            if(map.find(key) == map.end()){
                map[key] = new Node(key);
                dll->addNode(map[key]);
            }
            else{
                dll->seHead(map[key]);
            }
        }
        T1 evict(){
            T1 key = dll->tail->key;
            dll->removeNode(dll->tail);
            map.erase(key);
            return key;
        }

};