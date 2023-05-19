#include<iostream>
using namespace std;

int graph[100][100];

void dfs(int ver,int edge)
{
    int stack[10],visit[10];
    int v,top=0;
    cout << "\nEnter the initial vertex to start the DFS traversal with: ";
    cin >> v;
    cout << "\nThe DFS traversal on the given graph is : \n";
    cout << v << "\t";

    for(int i=1;i<ver;i++)
    {
        for(int j=ver;j>=0;j--)
        {
            if(graph[v][j]==1&& visit[j]!=1)
            {
                visit[j]=1;
                stack[top]=j;
                top++;
            }
        }
        v=stack[--top];
        cout<<v<<"\t";
    }
}

int main()
{
    int edg,ver,st,en;
    cout <<"Enter no of vertices:"<<endl;
    cin >> ver;
    cout <<"Enter no of edges:"<<endl;
    cin >> edg;
    for(int i=0; i<edg;i++)
    {
        cout <<"Enter the start and end vertex of the edges: "<<endl;
        cin>>st>>en;
        graph[st][en]=1;
    }
    dfs(ver,edg);
}
