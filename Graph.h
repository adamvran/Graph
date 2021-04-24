#include <map>
#include <vector>
using namespace std;
class Graph
{
private:
    class Vertex
    {
    public:
        int id;
        int value;
        int color = 0;

        vector<Vertex*> neighbors;

        Vertex(int id, int value):id(id), value(value){}
    };
    map<int, Vertex*> vertexMap;
    int currentId = 0;
public:
    void createVertex(int value);
    void createUnorientedEdge(int value1, int value2);
    void print();
    int breadthFirstSearch(int value);
};
