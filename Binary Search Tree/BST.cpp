#include "Node.h"
#include <iostream>
using namespace std;

class BST{
private:
    int length;
    Node* root;
public:
    BST(){
        root = NULL;
    }

    int insert(int key){
        if(root == NULL){
            this->root = new Node(key);
        }
        else{
            Node* current = root;
            while(current != NULL){
                if(key < current->getX()){
                    //Go Left
                    if(current->getLeft() == NULL){
                        current->setLeft(new Node(key));
                        return 1;
                    }else{
                        current = current->getLeft();
                    }
                }else if(key > current->getX()){
                    //Go right
                    if(current->getRight() == NULL){
                        current->setRight(new Node(key));
                        return 1;
                    }else{
                        current = current->getRight();
                    }
                }else{
                    cout << "insert:\tno duplicated vertex allowed." << endl;
                    return 0;
                }
            }
        }
        return 0;          
    }

    void remove_root(){
        if(root != NULL){
            Node* delPtr = root;
            int rootKey = root->getX();
            
            if(root->getLeft() == NULL && root->getRight() == NULL){
                this->root = NULL;
                delete delPtr;
                cout << "Root deleted." <<endl;
            }
            else if(root->getLeft() == NULL && root->getRight() != NULL){
                root = root->getRight();
                delPtr->setRight(NULL);
                delete delPtr;
                cout << "The node " << rootKey << " was deleted.\n" << root->getX() << " is the new root." << endl;
            }
            else if(root->getLeft() != NULL  && root->getRight() == NULL){
                root = root->getLeft();
                delPtr->setLeft(NULL);
                delete delPtr;
                cout << "The node " << rootKey << " was deleted.\n" << root->getX() << " is the new root." << endl;
            }
        }else{
            cout << "The tree is empty." << endl;
        }
    }

    void remove_current(int params){

    }

    void remove(int key){
        remove(key, this->root);
    }

    void remove(int key, Node* parent){
        if(this->root != NULL){
            if(root->getX() == key){
                remove_root();
            }
            else{
                if(key < parent->getX() && parent->getLeft() != NULL){
                    if(parent->getLeft()->getX() == key){
                        remove_current(123);
                    }
                    else{
                        remove(key, parent->getLeft());
                    }                    
                }
                else if(key > parent->getX() && parent->getRight() != NULL){
                    if(parent->getRight()->getX() == key){
                        remove_current(321);
                    }
                    else{
                        remove(key, parent->getRight());
                    }
                }
                else{
                    cout << "The key (" << key << ") was not found." << endl;
                }
            }
        }
        else{
            cout  << "The tree is empty" <<endl;
        }
    }


    void prefix_left(){
        prefix_left(this->root);}
    void prefix_left(Node* current){
        if(current != NULL){
            cout << current->getX() <<endl;
            prefix_left(current->getLeft());
            prefix_left(current->getRight());
        }
    }

    void prefix_right(){
        prefix_right(this->root);
    }
    void prefix_right(Node* current){
        if(current != NULL){
            cout << current->getX() << endl;
            prefix_right(current->getRight());
            prefix_right(current->getLeft());
        }
    }

    void central_left(){
        central_left(this->root);
    }
    void central_left(Node* current){
        if(current != NULL){
            central_left(current->getLeft());
            cout << current->getX() << endl;
            central_left(current->getRight());
        }
    }

    void central_right(){
        central_right(this->root);
    }
    void central_right(Node* current){
        if(current != NULL){
            central_right(current->getRight());
            cout << current->getX() << endl;
            central_left(current->getLeft());
        }
    }

    void posfix_left(){
        posfix_left(this->root);
    }
    void posfix_left(Node* current){
        if(current != NULL){
            posfix_left(current->getLeft());
            posfix_left(current->getRight());
            cout << current->getX() << endl;
        }
    }

    void posfix_right(){
        posfix_right(this->root);
    }
    void posfix_right(Node* current){
        if(current != NULL){
            posfix_right(current->getRight());
            posfix_right(current->getLeft());
            cout << current->getX() << endl;
        }
    }


};

int main(){
    BST bst;
    bst.insert(10);
    bst.insert(8);
    bst.insert(7);

    cout << "print:\t" << endl;
    bst.prefix_left();

    bst.remove(10);
    bst.prefix_left();
}