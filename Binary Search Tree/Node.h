#include <stdio.h>
#include <stdlib.h>

class Node
{
    private:
        int x;
        Node* next;
    public:
        Node(){
            next = NULL;        
        }
        
        Node(int x){
            this->x = x;
            this->next = NULL;
        }
        
        int getX(){
            return x;
        }
        
        void setX(char c){
            this->x = x;
        }
        
        Node* getNext(){
            return next;
        }
        
        void setNext(Node *next){
            this->next = next;
        }
};

