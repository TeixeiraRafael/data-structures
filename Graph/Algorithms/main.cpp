#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Graph.cpp"

using namespace std;

int main(){
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(1, 2, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 9);
    g.addEdge(7, 8, 7);
    g.addEdge(8, 2, 2);
    g.addEdge(8, 6, 6);
    g.addEdge(2, 5, 4);
    g.addEdge(5, 3, 14);
    g.addEdge(1, 7, 11);
    //g.print();

    printf("Dijkstra:\n");
    dijkstra(g, 0);
}