#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <functional>

#define INF 1000000000

using namespace std;


class Graph{
public:
    int n;
    vector< pair<int, int> > *adj; 

    Graph(int nodes){
        n = nodes;
        adj = new vector< pair<int, int> >[n]; //adj is a n-sized array of lists
    }

    void addEdge(int n1, int n2, int w){
        adj[n1].push_back(make_pair(n2, w));
        adj[n2].push_back(make_pair(n1, w));
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

    int getSize(){
        return n;
    }
};

void prim(Graph G, int s){
    vector<int> key(G.n, INF);
    vector<int> parent(G.n, -1);
    vector<bool> inMST(G.n, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > Q;

    key[s] = 0;
    Q.push(make_pair(0, s));

    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        inMST[u] = true;                //Adiciona o nó na árvore

        //Itera seus nós adjacentes buscando o menor caminho:
        vector<pair<int, int> >::iterator i;
        for(i = G.adj[u].begin(); i != G.adj[u].end(); i++){
            int v = (*i).first;         //Extrai o nó
            int w = (*i).second;        //E o seu peso
            if(!inMST[v] && key[v] > w){
                key[v] = w;
                Q.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < G.getSize(); ++i)
        printf("%d - %d\n", parent[i], i);
}