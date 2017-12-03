#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Graph.cpp"

using namespace std;

int main(){
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 4, 2);
    g.addEdge(0, 5, 7);
    g.addEdge(4, 2, 3);
    g.addEdge(4, 1, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(5, 3, 2);
    g.addEdge(1, 5, 1);
    //g.print();

    printf("Dijkstra:\n");
    dijkstra(g, 2);
}