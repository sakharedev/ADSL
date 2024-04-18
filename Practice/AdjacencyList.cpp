#include <iostream>
#include <string>

using namespace std;

struct Edge
{
    char dest;
    int cost;
    struct Edge *link;
};

struct Node
{
    struct Node *next;
    char name;
    struct Edge *adj;
};

class Graph
{
    Node* start;

    public: 
        Graph()
        {
            start = nullptr;
        }
        void scanGraph(int vertices, int edges);
        void displayGraph(int vertices, int edges);
};

void Graph::scanGraph(int vertices, int edges)
{
    int cost;
    char source, destination;
    int n = 65;
    Node *ptr, *bptr;
    Edge *p, *bp;
    for (int i = 0; i < vertices; i++)
    {
        ptr = new Node;
        ptr->name = (n+i);
        ptr->next = nullptr;
        ptr->adj = nullptr;
        if (start == nullptr)
        {
            start = nullptr;
        }
        else
        {
            bptr = start;
            while (bptr->next != nullptr)
            {
                bptr = bptr->next;
            }
            bptr->next = ptr;
        }
    }

    cout<<endl<<"Plese Enter Source City and Destination City";
    cout<<"Starting from A upto number of cities like A,B,C,D";
    for (int i = 0; i < edges; i++)
    {
        l1:
            cout<<"Edge No. -> "<<i+1<<endl;
            cout<<"Source City-> ";
            cin>>source;
            cout<<"Destination City-> ";
            cin>>destination;
            cout<<"Cost-> ";
            cin>>cost;

            if ((source >= 65 && source < (65+vertices) && (destination >= 65 && destination <(65+vertices))))
            {
                bptr = start;
                while (bptr->name != source)
                {
                    bptr = bptr->next;
                }
                if (bptr!=nullptr)
                {
                    p = new Edge;
                    p->dest = destination;
                    p->cost = cost;
                    p->link = nullptr;
                    bp = bptr->adj;
                    if(bp == nullptr)
                    {
                        bptr->adj = p;
                    }
                    else
                    {
                        while (bp->link != nullptr)
                        {
                            bp = bp->link;
                            bp->link = p;
                        }
                        
                    }
                }
                
            }
            else
            {
                cout<<"Enter Proper input in a range of vertices"<<endl;
                goto l1;
            }
    }
}

void Graph::displayGraph(int vertices, int edges)
{
    Node *ptr;
    Edge *p;
    ptr = start;
    while (ptr!=nullptr)
    {
        cout<<endl;
        cout<<ptr->name;
        p = ptr->adj;
        while (p != nullptr)
        {
            cout<<"--> "<<p->dest<<" & cost"<<p->cost;
            p = p->link;
        }
        ptr = ptr->next;
        if (ptr != nullptr)
        {
            cout<<endl<<"|";
        }
        
    }

}

int main()
{
    Graph g;
    cout<<"Enter number of Vertices: ";
    int vertices;
    cin>>vertices;
    int edges;
    cout<<"Enter number of Edges: ";
    cin>>edges;
    g.scanGraph(vertices, edges);
    g.displayGraph(vertices, edges);
    return 0;
}