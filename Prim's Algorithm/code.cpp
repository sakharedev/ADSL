#include<iostream>
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
     wt=0;
    }
    int allperm(int);
    void initgraph();   //initailize matrix with 0
    void displayg(int v,int e); // display adj mat
    void scangraph(int v,int e); // input graph
    void span(int v,int e);
};

int graph::allperm(int v)
{

int i;
for(i=0;i<v;i++)
   if(state[i].stat==0)
     return 0;
return 1;
}

void graph::span(int v,int e)
{

int current,count,min,u1,v1;
    for(int i=0;i<v;i++)
    {
    state[i].pred=0;
    state[i].dist=999;
    state[i].stat=0; //0  means not visited
    }
    state[0].pred=0;
    state[0].dist=0;
    state[0].stat=1;
    current=0;
    count=0;
    while(allperm(v)!=1)
    {
        for(int i=0;i<v;i++)
        {
            if(adjmat[current][i]>0 && state[i].stat==0)
            {
                if(adjmat[current][i]< state[i].dist)
                {
                    state[i].pred=current;
                    state[i].dist=adjmat[current][i];
                }           
            }
        }
        min =999;
        for(int i=0;i<v;i++)
        {
             if(state[i].stat ==0 && state[i].dist < min)
            {
            min=state[i].dist;
            current=i;
            }
        }       
        cout<<endl<<"current"<<current;   
        state[current].stat=1;
        u1=state[current].pred;
        v1=current;
        tree[count].u=u1;
        tree[count].v=v1;
        count++;

        wt=wt+ adjmat[u1][v1];
    }

    cout<<endl<<"set of lines for connecting city with min. cost is"<<endl;
    for(int i=0;i<count;i++)
     {
        cout<<"city"<<tree[i].u+1<<"->";
        cout<<"city"<<tree[i].v+1<<endl;
     }
}
void graph::initgraph()   //constuctor to intialize Graph
    {
    int i,j;
    for(i=0;i<10;i++)
    {
    for(j=0;j<10;j++)
        adjmat[i][j]=0;
    }
    }

void graph::displayg(int v,int e)
    {
    int i,j;
    for(i=0;i<v;i++)
    {
    cout<<endl;
    for(j=0;j<v;j++)
        cout<<adjmat[i][j]<<" ";
    }
    }

void graph::scangraph(int v ,int e)
{
int i,s,d,cost;

cout<<"please enter source city and destination city  of the edge(city no must be between 1 to"<<v<<")";
for(i=0;i<e;i++)
{
l1:
 cout<<endl<<"Edge no ->  "<<i+1<<endl;
 cout<<"Source city->";
 cin>>s;
 cout<<"Destination city-> ";
 cin>>d;
 cout<<"Cost of Conecting 2 city";
 cin>>cost;
 if((s>=1 && s<=v) && (d>=1 && d<=v))
{
    if((adjmat[s-1][d-1]==0) && (adjmat[d-1][s-1] == 0))
    {
        adjmat[s-1][d-1]=cost;
        adjmat[d-1][s-1]=cost;
    }
    else
    {
    cout<<"Edge already exist";
         goto l1;
    }
}
else
{
   cout<<"Please Enter correct vertex no's";
     goto l1;   
}
}
}
int main()
{
int ch,cont,v,e;
graph g1;
do
{
cout<<endl<<"Menu";
cout<<endl<<"1.Create Graph for offices ";
cout<<endl<<"2.Display Graph";
cout<<endl<<"3.min cost cities";
cout<<endl<<"Enter Choice";
cin>>ch;
switch(ch)
{
case 1:
    g1.initgraph();
    cout<<"No of offices ?";
    cin>>v;
    cout<<"No of leased line ?";
    cin>>e;
    g1.scangraph(v,e);
    break;
case 2:
    g1.displayg(v,e);
    break;
case 3:
    g1.span(v,e);
    break;

}
cout<<"do u want to continue?(1 for continue)";
cin>>cont;
}while(cont==1);
return 0;
}
