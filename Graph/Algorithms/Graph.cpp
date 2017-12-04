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

void dijkstra(Graph G, int s){
    vector<int> dist(G.n, INF);     //Definindo todas as distâncias como infinitas
    dist[s] = 0;                    //Dstância do nó de origem até ele mesmo é 0
    
    //Fila de prioridade de pares (distancia, nodo) ordenada pelo menor valor
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > Q;
    Q.push(make_pair(0, s));

    while(!Q.empty()){
        //Pega e remove o primeiro par da lista
        pair<int, int> front = Q.top(); Q.pop();
        int u = front.second;
        int d = front.first;

        if(d > dist[u]) continue;
        //Percorre os nós vizinhos de U procurando o com menor distância
        for(int j = 0; j < G.adj[u].size(); j++){
            pair<int, int> v = G.adj[u][j]; //Vizinho atual de U
            int alt = dist[u] + v.second; 
            if(alt < dist[v.first]){ //Se a distância até o nó atual + peso até o vizinho for menor que a distância até o vizinho
                dist[v.first] = alt; //Atualiza a distância com esse melhor caminho encontrado
                Q.push(make_pair(dist[v.first], v.first)); //Insere nó o vizinho na fila de prioridade
            }
        }
    }
    for (int i = 0; i < G.n; i++) // index + 1 for final answer
        printf("Dist[%d] = %d\n", i, dist[i]);
};