#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
    //dsfsd
    Graph g;
    int N = 10;

    for (int i = 0; i < N; ++i)
        g.createVertex(i);

    for (int i = 0; i < N - 1; ++i)
        g.createUnorientedEdge(i, i+1);

    g.createUnorientedEdge(0, 9);
    g.print();

    g.breadthFirstSearch(8);

    return 0;
}
