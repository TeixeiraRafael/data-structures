#include "Node.h"

class LinkedList
{
    private:
        int length;
        Node* head;
    public:
        LinkedList(){
            length = 0;
            head = NULL;
        }
        
        void append(Node *node){
            //se a lista estiver vazia
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
                //Adiciona o nodo de entrada como next do último nodo da lista
                current->setNext(node);
                length++;
            }
        }
        
        void insert(int pos, Node *node){
            if(pos < 0 || pos > length){
                printf("insert: Posição inválida\n");
            }
            else{
                if(pos == 0){
                    Node *aux = head;
                    head = node;
                    node->setNext(aux);
                    length++;
                }
                else{
                    Node* current = head;
                    for(int i = 0; i < pos-1; i++){
                        current = current->getNext();
                    }
                    Node* aux = current->getNext();
                    node->setNext(aux);
                    current->setNext(node);
                    length++;
                }
                
            }
            
        }
        
        void print(){
            //se a lista estiver vazia
            if(head == NULL){
                printf("A lista está vazia\n");
            }
            //se houver pelo menos um item
            else{
                Node* current = head;
                //percorre os nodos até o último
                while(current != NULL){
                    int x = current->getX();
                    int y = current->getY();
                    printf("print: (%d, %d)\n", x, y);
                    current = current->getNext();                    
                }
            }        
        }
        
        void remove(int pos){
            if(pos < 0 || pos > length){
                printf("remove: Posição inválida\n");
            }
            else{
                if(pos == 0){
                    head = head->getNext();
                    length--;
                }
                else{
                    get(pos-1)->setNext(get(pos+1));
                    length--;
                }
                
            }
        }
        
        Node* get(int pos){
            if(pos < 0 || pos > length){
                printf("get: Posição inválida\n");
                return NULL;       
            }else{
                Node* current = head;
                for(int i = 0; i < pos; i++){
                    current = current->getNext();
                }
                return current;
            }                
        }
        
        int getLength(){
            return length;
        }
        
        LinkedList* sublist(int x, int x0){        
            if(x < 0 || x0 >= length){
                printf("sublist: Posição inválida\n");
            }else{
                printf("sublist(%d, %d):\n" ,x, x0);
                printf("x = %d\n", x);
                printf("x0 = %d\n", x0);

                LinkedList* sub = new LinkedList();
                
                for(int i = x; i <= x0; i++){
                    get(i)->print();
                    sub->append(get(x));
                }
                printf("me noiei\n");
                return sub;
            }
        }
        
        
};

int main(){
    LinkedList* l = new LinkedList();
    int k;
    
    for(int i = 0; i < 10; i++){
        Node* n = new Node(i, i);
        l->append(n);        
    }    
    l->print();
    printf("Length = %d\n", l->getLength());

    LinkedList* sublist = new LinkedList();
    sublist = l->sublist(2,5);
    sublist->print();
}















