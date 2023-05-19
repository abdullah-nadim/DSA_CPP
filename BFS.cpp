#include<iostream>
#include<queue>
using namespace std;

int graph[100][100];

void bfs(int ver, int edg)
{
    queue<int> q;
    int visit[100],v;
    cout << "\nEnter the initial vertex to start the BFS traversal with: ";
    cin >> v;
    cout << "\nThe BFS traversal on the given graph is : \n";
    cout << v << "\t";
    for(int i=1;i<ver;i++)
    {
        for(int j=100;j>=0;j--)//
        {
            if(graph[v][j]==1&& visit[j]!=1)
            {
                visit[j]=1;
                q.push(j);
               // cout<<"Check:"<<j<<"\t";
            }
        }
        v=q.front();
        q.pop();
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
    bfs(ver,edg);
}
