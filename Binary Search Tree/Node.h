#include <stdio.h>
#include <stdlib.h>

class Node
{
    private:
        int x;
        Node* left;
        Node* right;
    public:
        Node(){
            right = NULL;
            left = NULL;
        }
        
        Node(int x){
            this->x = x;
            this->left = NULL;
            this->right = NULL;
        }
        
        int getX(){
            return x;
        }
        
        void setX(int x){
            this->x = x;
        }
        
        Node* getLeft(){
            return left;
        }
        
        Node* getRight(){
            return right;
        }
        
        void setLeft(Node* left){
            this->left = left;
        }

        void setRight(Node* right){
            this->right = right;
        }

        bool isLeaf(){
            if(this->left == NULL && this->right == NULL)
                return 1;
            return 0;
        }
};

