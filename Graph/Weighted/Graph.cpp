#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Graph{

private:
    int n;
    vector< pair<int, int> > *adj; 

public:
    Graph(int nodes){
        n = nodes;
        adj = new vector< pair<int, int> >[n]; //adj is a n-sized array of lists
    }

    void addEdge(int n1, int n2, int w){
		adj[n1].push_back(make_pair(n2, w));
    }

    void print(){
		for(int i = 0; i < n; i++){
			printf("Node %d edges with:\n", i);
			for(int j = 0; j < adj[i].size(); j++){
				printf("\tNode %d with weight %d\n", adj[i][j].first, adj[i][j].second);
			}
			printf("\n");
		}        
    }
};

int main(){
    Graph g(6);
    g.addEdge(0, 2, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 5);
    g.addEdge(2, 3, 6);
    g.addEdge(4, 5, 7);
    g.print();
}
