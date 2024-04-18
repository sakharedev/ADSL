#include <iostream>
int st[10],top=-1,Q[10],front =-1,rear=-1;

void insertQ(int v)
{
    if(rear==-1)  //insertning first element
     {
         rear=front=0;
         Q[rear]=v;
         
     }
     else if(rear<=8)
     {
         Q[++rear]=v;
     }
     else
     {
         std::cout<<"Q full";
     }
}

int deleteQ()
{
    int v=-1;
    if(front==-1)
      std::cout<<"\n Q empty";
    else
    {
         v=Q[front];
         front++;
    }
      return v;
}

void push(int v)
{
    if(top<=9)
      st[++top]=v;
     else
     std::cout<<"stack full";
}

int pop()
{
    int v =-1;
    if(top!=-1)
    {
        v=st[top];
      top--;
    }
    else
     {
         std::cout<<"stack empty ";
     }
     return v;
}



int main()
{
    int V,E;
    char Dir;
    std::cout<<"How many Vertices ?";
    std::cin>>V;
    int adjMat[V+1][V+1];
   
    for(int i =1;i<=V;i++)
    {
      for(int j =1;j<=V;j++)
      {
          adjMat[i][j]=0;
      }
         
    }
   
    std::cout<<"How many Edges ?";
    std::cin>>E;
    std::cout<<"Graph is Directed /Undirected ? D/U";
    std::cin>>Dir;
    std::cout<<"enter edges of the graph";
    int s,d,wt;
    for(int i =0;i<E;i++)
    {
        std::cout<<"Enter source,destination and wt of the edge - "<<i+1;
        std::cin>>s>>d>>wt;
        if((s>=1 && s<=V)&&(d>=1 && d<=V))
        {
            adjMat[s][d]=wt;
            if(Dir=='U')
            {
                adjMat[d][s]=wt;
            }
        }
        else
        {
            std::cout<< "\nPlease enter valid source and destination for edge";
            i--;
        }
    }
   
    std::cout<<std::endl<<"Adjcancy Matrix is : - "<<std::endl;
      for(int i =1;i<=V;i++)
      {
          std::cout<<"\n";
      for(int j =1;j<=V;j++)
      {
          std::cout<<adjMat[i][j]<<" ";
      }
         
      }
     
     
      //Code for DFS
     int visited[V+1],sv;
     for(int i=1;i<=V;i++)
         visited[i]=0;
         
     std::cout<<"From where to start dfs traversal";
     std::cin>>sv;
     std::cout<<"\nDFS Traversal is \n" ;
     push(sv);
     while(top!=-1)
     {
         sv=pop();
         if(visited[sv]==0)
         {
             std::cout<<sv<<" "; //printing vertex because not visited
             visited[sv]=1;  //Marking it as visited
             for(int i =1;i<=V;i++)
             {
                 if(adjMat[sv][i]>0)   /// pushing adjacent vertices
                   push(i);
             }
         }
     }
     //code for bfs
     
     std::cout<<"From where to start Bfs traversal";
     std::cin>>sv;
     
     for(int i=1;i<=V;i++)
         visited[i]=0;
     
     std::cout<<"\nBFS Traversal is \n" ;
     insertQ(sv);
     visited[sv]=1;
     std::cout<<sv<<" ";
     while(front!=rear+1)
     {
         sv=deleteQ();
     
             for(int i =1;i<=V;i++)
             {
                 if((adjMat[sv][i]>0)  &&(visited[i]==0))  /// pushing adjacent vertices
                   {
                       std::cout<<i<<" ";
                       insertQ(i);
                       visited[i]=1;
                   }
             }
         
     }


    return 0;
}
