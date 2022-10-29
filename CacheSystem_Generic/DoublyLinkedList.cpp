#include <iostream>
#include <string>
#include "Node.h"
using namespace std;
template<class T1>
class DoublyLinkedList{
    public:
        Node<T1>* head;
        Node<T1>* tail;
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }
        virtual ~DoublyLinkedList(){
            if(head != NULL)
                delete head;
            if(tail != NULL)
                delete tail;
        }
        void addNode(Node<T1>* node){
            if(head == NULL){
                head = node;
                tail = node;
            }
            else
                seHead(node);
        }
        void seHead(Node<T1>* node){
            if(head != node){
                unBindNode(node);
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        void removeNode(Node<T1>* node){
            if(node == head){
                head = head->next;
            }
            if(node == tail){
                tail = tail->prev;
            }
            unBindNode(node);
        }
    private:
        void unBindNode(Node<T1>* node){
            if(node->next != NULL){
                node->next->prev = node->prev;
                node->next = NULL;
            }
            if(node->prev != NULL){
                node->prev->next = node->next;
                node->prev = NULL;
            }
            
        }
    
};