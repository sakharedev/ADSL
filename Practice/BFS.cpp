#include <iostream>
using namespace std;
#define MAX_SIZE 100

int queue[MAX_SIZE], front = -1, rear = -1;

void insertQ(int vertex)
{
    if (rear == -1)
    {
        rear = front = 0;
        queue[rear] = vertex;
    }
    else if(rear < MAX_SIZE)
    {
        queue[++rear] = vertex;
    }
    else
    {
        cout<<"queue is full"<<endl;
    }
}

int deleteQ()
{
    int v = -1;
    if(front == -1)
    {
        cout<<"Queue is Empty"<<endl;
    }
    else
    {
        v = queue[front];
        front++;
    }
    return v;
}

int main()
{
    int vertices, edges;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    cout<<"Enter Number of Edges: ";
    cin>>edges;
    char Dir;
    cout<<"Graph is Directed/Undirected(D/U): ";
    cin>>Dir;

    int adjMat[vertices+1][edges+1];
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            adjMat[i][j] = 0;
        }
    }

    cout<<"Enter Source, Destination and Weight of each edge"<<endl;
    int source, destination, weight;
    for (int i = 0; i < edges; i++)
    {
        cout<<"Edge "<<i+1<<endl;
        cout<<"Source-> ";
        cin>>source;
        cout<<"Destination-> ";
        cin>>destination;
        cout<<"weight-> ";
        cin>>weight;
        if (source>=1 && source <= vertices && destination >= 1 && destination <= vertices)
        {
            adjMat[source][destination] = weight;
            if(Dir == 'U')
            {
                adjMat[destination][source] = weight;
            }
        }
        else
        {
            cout<<"Enter proper source and destination"<<endl;
            i--;
        }
    }
    
    for (int i = 1; i <= vertices; i++)
    {
        for (int j = 1; j <= vertices; j++)
        {
            cout<<adjMat[i][j];
        }
        cout<<endl;
    }
    
    int start;
    cout<<"Enter the vertex from where you want to start the traversal: ";
    cin>>start;
    int visited[vertices+1];
    for (int i = 1; i <= vertices; i++)
    {
        visited[i] = 0;
    }

    visited[start] = 1;
    insertQ(start);
    cout<<start<<" ";
    while(front != (rear+1))
    {
        start = deleteQ();
        for (int i = 1; i <= vertices; i++)
        {
            if (adjMat[start][i]>0 && visited[i] == 0)
            {
                cout<<i<<" ";
                insertQ(i);
                visited[i] = 1;
            }
            
        }
        
    }
    
}