#pragma once
#include <iostream>
#include <string>
using namespace std;
template<class T1>
class Node{
    public:
        Node* prev;
        Node* next;
        string key;
        Node(T1 key){
            this->key = key;
            prev = NULL;
            next = NULL;
        }
        ~Node(){
            if(prev != NULL)
                delete prev;
            if(next != NULL)
                delete next;
        }
        
};