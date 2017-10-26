#include <stdio.h>
#include <list>
using namespace std;
class Graph{
private:
    int n;
    list<int> *adj; 

public:
    Graph(int nodes){
        n = nodes;
        adj = new list<int>[n]; //adj is a n-sized array of lists
    }

    void addEdge(int n1, int n2){
		adj[n1].push_back(n2);
    }

    void removeEdge(int n1, int n2){
        adj[n1].remove(n2);
    }

    void print(){
		for(int i = 0; i < n; i++){
			printf("%d | ", i);
			for(list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++){
				printf("%d ", *it);
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
}
