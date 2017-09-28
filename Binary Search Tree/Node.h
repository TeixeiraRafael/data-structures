#include <stdio.h>
#include <stdlib.h>

class Node
{
    private:
        int x;
        Node* left;
        Node* right;
        Node* parent;
    public:
        Node(){
            right = NULL;
            left = NULL;
            parent = NULL;
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
        
        Node* getParent(){
            return parent;
        }
        
        void setLeft(Node* left){
            this->left = left;
        }

        void setRight(Node* right){
            this->right = right;
        }
        
        void setParent(Node* parent){
            this->parent = parent;
        }

        bool isLeaf(){
            if(this->left == NULL && this->right == NULL)
                return 1;
            return 0;
        }

        bool hasLeft(){
            if(this->left != NULL)
                return 1;
            return 0;           
        }

        bool hasRight(){
            if(this->right != NULL)
                return 1;
            return 0;           
        }
        
        bool hasParent(){
            if(this->parent != NULL)
                return 1;
            return 0;           
        }
        
};

