#include <iostream>
#include <string>

using namespace std;

struct edge
{
    char dest;
    int cost;
    struct edge *link;
};

struct node
{
    struct node *next;
    char name;
    struct node *adj;
};

class Graph
{
    node* start;

    public: 
        Graph()
        {
            start = nullptr;
        }
        void scanGraph(int vertices, int edges);
        void displayGraph(int vertices, int edges);
}

void Graph::scanGraph(int vertices, int edges)
{
    
}