#include<iostream>
using namespace std;

int st[10], top = -1, Q[10], front=-1, rear = -1;

void insertQ(int v) {
    if( front == -1 && rear == -1) {
        rear = front = 0;
        Q[rear] = v;
    }
    else if(rear < 9) {
        Q[++rear] = v;
    }

    else {
        cout<<"Queue is full"<<endl;
    }
}

int deleteQ() {
    int v = -1;
    if(front == rear+1) {
        cout<<"Queue Empty"<<endl;
    }
    else if(front == -1 && rear == -1) {
        cout<<"Queue Empty"<<endl;
    }
    else {
        v = Q[front];
        front++;
    }

    return v;
}

void push(int v)
{
    if(top < 9)
    {
        st[++top] = v;
    }
    else
    {
        cout<<"Stack is Full";
    }
}

int pop()
{
    int v = -1;
    if(top!=-1) {
        v = st[top];
        top--;
    }
    else {
        cout<<"Stack is Empty";
    }
    return v;
}



int main()
{

    int V, E;
    char Dir;

    cout << "Enter How many vertices? ";
    cin >> V;

    int adjMat[V + 1][V + 1];

    

    // cout << "Enter Number of edges: ";
    // cin >> E;

    cout << "Graph is directed/undirected (D/U): ";
    cin >> Dir;
    int sr, ds, wt;

    for (int i = 0; i <= V; i++) {
        for (int j = 0; j <= V; j++) {
            adjMat[i][j] = 0;
        }
        cout << endl;
    }


    for (int i = 0; i < V; i++) {
         // Label for goto statement
        cout << "Enter source, destination, and weight of the edge " << i + 1 << ": ";
        cin >> sr >> ds >> wt;

        if (sr >= 1 && sr <= V && ds >= 1 && ds <= V) {
            adjMat[sr][ds] = wt;
            if (Dir == 'U') // Use single quotes for characters
                adjMat[ds][sr] = wt;
        } else {
            cout << "Enter correct vertices for the edge." << endl;
            i--; // Jump to label l1 to repeat input
        }
    }

    // Print adjacency matrix
    cout << "Adjacency Matrix is: " << endl;
    for (int i = 1; i <= V; i++) 
    {
        for (int j = 1; j <= V; j++) 
        {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    int visited[V+1];
    int sv;
    cout<<"Enter from which vertex you want to start traversal: ";
    cin>>sv;
    for(int i = 1; i <= V; i++) 
    {
        visited[i] = 0;
    }

    //DFS
    // push(sv);
    // while(top!=-1) {
    //     sv = pop();
    //     if(visited[sv] == 0) {
    //         cout<<sv<<" ->";
    //         visited[sv] = 1;
    //         for(int i = 1; i <= V; i++) {
    //             if(adjMat[sv][i]>0) {
    //                 push(i);
    //             }

    //         }
    //     }
    // }

    //BFS
    insertQ(sv);
    visited[sv] = 1;
    while (front!=(rear+1))
    {
        sv = deleteQ();
        cout<<sv<< " ->";
        for (int i = 0; i <= V; i++)
        {
            if((adjMat[sv][i]>0) && visited[i]==0)
            {
                insertQ(i);
                visited[i]=1;
            }
        }
        
    }
    

}