#include <stdio.h>

class Graph{
private:
    int n;
    int **matrix;

public:
    Graph(int nodes){
        n = nodes;
        matrix = new int*[n];
        for(int i = 0; i <  n; i++){
            matrix[i] = new int[n];
            for(int j = 0; j <n; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int n1, int n2){
        if(n1 > n2)
            matrix[n1-1][n2-1] = 1;
        else
            matrix[n2-1][n1-1] = 1;
    }

    int checkEdge(int n1, int n2){
        return n1 > n2 ? matrix[n1-1][n2-1] : matrix[n2-1][n1-1];
    }

    void removeEdge(int n1, int n2){
        if(n1  > n2)
            matrix[n1-1][n2-1] = 0;
        else
            matrix[n2-1][n1-1] = 0;
    }

    void print(){
        printf("print:\t\n");
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
};

int main(){
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.print();
    g.removeEdge(4, 5);
    //printf("\n");
    g.print();
}