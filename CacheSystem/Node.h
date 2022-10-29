#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        Node* prev;
        Node* next;
        string key;
        Node(string key){
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