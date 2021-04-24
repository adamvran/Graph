#include "Graph.h"
#include <iostream>
#include <queue>

void Graph::createVertex(int value)
{
    vertexMap[value] = new Vertex(currentId, value);
    currentId++;
}

void Graph::createUnorientedEdge(int value1, int value2)
{
    // Linear complexity -> SOLVE!!!
    auto it = vertexMap.find(value1); //find má logaritmickou složitost
    auto it2 = vertexMap.find(value2);

    if (it != vertexMap.end() && it2 != vertexMap.end())
    {
        Vertex* vertex1 = it->second;
        Vertex* vertex2 = it2->second;

        vertex1->neighbors.push_back(vertex2);
        vertex2->neighbors.push_back(vertex1);
    }

}

void Graph::print()
{
    for(auto mapElement : vertexMap)
    {
        Vertex* currentVertex = mapElement.second;

        if (!currentVertex->neighbors.empty())
            for(auto neightbor : currentVertex->neighbors)
                cout << currentVertex->value << " -> " << neightbor->value <<endl;

        else cout << currentVertex->value << endl;
    }
}

int Graph::breadthFirstSearch(int value)
{
    Vertex* currentVertex = vertexMap.at(0);
    queue<Vertex*> que;

    que.push(currentVertex);
    //currentVertex->color = 1;
    while (!que.empty())
    {
        currentVertex = que.front();
        que.pop();

        currentVertex->color = 2;
        cout << currentVertex->value << endl;

        if (currentVertex->value == value)
            return currentVertex->id;

        for (auto neightbor : currentVertex->neighbors)
            if (neightbor->color == 0)
            {
                que.push(neightbor);
                neightbor->color = 1;
            }
    }
    return 0;
}
