#include "Node.h"
#include <iostream>
using namespace std;
class Stack
{
    private:
        int length;
        Node* head;
    public:
        Stack(){
            length = 0;
            head = NULL;
        }
        
        void insert(Node *node){
            //se a pilha estiver vazia
            if(head == NULL){
                head = node;
                length++;
            }
            //se houver pelo menos um item
            else{
                Node* current = head;
                //percorre os nodos até o último
                while(current->getNext() != NULL){
                    current = current->getNext();
                }
                //Adiciona o nodo de entrada como next do último nodo da pilha
                current->setNext(node);
                length++;
            }
        }
        
        Node* get(){
            Node* current = head;
            for(int i = 0; i < length-1; i++){
                current = current->getNext();
            }
            return current;                
        }
        void pop(){
            Node* current = head;
            for(int i = 0; i < length-1; i++){
                current = current->getNext();
            }
            current->setNext(NULL);                
        }
        int getLength(){
            return length;
        }
};

int main(){
    Node *a = new Node('a');
    Node *b = new Node('b');
    Node *c = new Node('c');

    Stack* s = new Stack();

    s->insert(a);
    s->insert(b);
    Node* r = s->get();
    cout << (char)r->getC() << endl;
    s->pop();
    r = s->get();
    cout << (char)r->getC() << endl;
}