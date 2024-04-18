#include <iostream>
using namespace std;

struct node
{
    int pred;
    int dist;
    int stat;
};

struct edge
{
    int u,v;
};

class graph
{
    int adjmat[10][10];
    struct node state[10];
    struct edge tree[10];
    int wt;
    public:
        graph()
        {
            wt = 0;
        }
        int allperm(int);
        void initgraph();
        void span(int v, int e);
        
};