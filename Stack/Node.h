#include <stdio.h>
#include <stdlib.h>

class Node
{
    private:
        char c;
        Node* next;
    public:
        Node(){
            next = NULL;        
        }
        
        Node(char c){
            this->c = c;
            this->next = NULL;
        }
        
        int getC(){
            return c;
        }
        
        void setC(char c){
            this->c = c;
        }
        
        Node* getNext(){
            return next;
        }
        
        void setNext(Node *next){
            this->next = next;
        }
};

