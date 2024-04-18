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
    struct edge *adj;
};

class graph
{
    node *start;

    public:
        graph()
        {
            start = nullptr;
        }
        void displayg(int v, int e);
        void scangraph(int v, int e);
};

void graph::displayg(int v, int e)
{
    node *ptr;
    edge *p;
    ptr = start;
    while(ptr!=nullptr)
    {
        cout<<endl;
        cout<<ptr->name;
        p = ptr->adj;
        while(p != nullptr)
        {
            cout<<"--> "<<p->dest<<" & cost"<<p->cost;
            p = p->link;
        }
        ptr = ptr->next;
        if(ptr != nullptr)
        {
            cout<<endl<<"|";
        }
    }
}

void graph::scangraph(int v, int e)
{
    int cost;
    char s, d;
    int n = 65;
    node *ptr, *bptr;
    edge *p, *bp;
    for (int i = 0; i < v; i++)
    {
        ptr = new node;
        ptr->name = (n+i);
        ptr->next = nullptr;
        ptr->adj = nullptr;
        if (start == nullptr)
        {
            start = ptr;
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
    cout<<endl<<"Please enter source city and destination city ";
    cout<<"Starting from A upto number of cities like A,B,C,D";
    for (int i = 0; i < e; i++)
    {
        l1:
            cout<<endl<<"Edge no -> "<<i+1<<endl;
            cout<<"Source city-> ";
            cin>>s;
            cout<<"Destination city -> ";
            cin>>d;
            cout<<"cost-> ";
            cin>>cost;
            
            if((s>=65 && s<(65+v)) && (d>=65 && d<(65+v)))
            {
                bptr = start;
                while (bptr->name != s)
                {
                    bptr = bptr->next;
                }
                if(bptr!=nullptr)
                {
                    p = new edge;
                    p->dest = d;
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
                cout<<"Enter Proper input in range of vertices"<<endl;
                goto l1;
            }
    }
    
}


int main()
{
    int v, e, cont, ch;
    graph g1;
    do
    {
        cout<<endl<<"Menu";
        cout<<endl<<"1. Create Graph using Adjacency List";
        cout<<endl<<"2. Display Graph";
        cout<<endl<<"Enter Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter Number of Cities: ";
            cin>>v;
            cout<<"Enter Number of Flights: ";
            cin>>e;
            g1.scangraph(v, e);
            break;
        case 2:
            g1.displayg(v, e);
            break;
        }
        cout<<endl<<"Do you want to continue? (1 for Continue)";
        cin>>cont;
    } while(cont == 1);
    return 0;
}