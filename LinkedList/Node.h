#include <stdio.h>
#include <stdlib.h>

class Node
{
    private:
        int x, y;
        Node* next;
    public:
        Node(){
            x = 0;
            y = 0;
            next = NULL;        
        }
        
        Node(int x, int y){
            this->x = x;
            this->y = y;
            this->next = NULL;
        }
        
        void setX(int x){
            this->x = x;
        }
        
        void setY(int y){
            this->y = y;
        }
        
        void setNext(Node *next){
            this->next = next;
        }
        
        int getX(){
            return x;
        }
        
        int getY(){
            return y;
        }
        
        Node* getNext(){
            return next;
        }

        void print(){
            printf("(%x, %d)\n", x, y);
        }        
};

