#include <iostream>
using namespace std;

int main()
{
    int vertices, edges;
    char Dir;
    cout<<"Enter Number of verticec: ";
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;
    cout<<"Graph is Directed/Undirected(D/U): ";
    cin>>Dir;

    int adjMat[vertices][vertices];
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adjMat[i][j] = 0;
        }
    }
    int source, destinition, weight;
    for (int i = 0; i < edges; i++)
    {
        cout<<"Enter source destination and weight of edge "<<i+1<<": ";
        cin>>source>>destinition>>weight;
        if (source >= i+1 && source <= vertices && destinition >= i+1 && destinition <= vertices)
        {
            adjMat[source-1][destinition-1] = weight;
            if(Dir == 'U')
            {
                adjMat[destinition-1][source-1] = weight;
            }
        }
        else
        {
            cout<<"Enter proper values of Source and Destinition."<<endl;
            i--;
        }
    }
    
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
    
}