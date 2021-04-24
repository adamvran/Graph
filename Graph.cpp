#include "Graph.h"
#include <iostream>
#include <queue>

void Graph::createVertex(int value)
{
    vertexMap.emplace(currentId, new Vertex(currentId, value));
    currentId++;
}

void Graph::createUnorientedEdge(int value1, int value2)
{
    /*for (int i = 0; i < vertexMap.size(); ++i)
    {
        if (vertexMap[i]->value == value1)
        {

        }
    }*/

    // Linear complexity -> SOLVE!!!
    Vertex* vertex1 = nullptr;
    Vertex* vertex2 = nullptr;

    for (auto mapElement : vertexMap)
    {
        Vertex* currentVertex = mapElement.second;

        if (currentVertex->value == value1)
            vertex1 = currentVertex;

        if (currentVertex->value == value2)
            vertex2 = currentVertex;

        if (vertex1 != nullptr && vertex2 != nullptr)
            break;

    }

    if (vertex1 != nullptr && vertex2 != nullptr)
    {
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
}