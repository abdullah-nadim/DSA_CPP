#include<iostream>
using namespace std;
int graph[100][100];
void initial(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                graph[i][j]=0;
            }
    }
}

void input()
{

    char s,d;
    int e,si,di;
    cout<<"Number of edges: \n";
    cin>>e;
    while(e--){
    cout<<"Enter source: \n";
    cin>>s;
    cout<<"Enter destination: \n";
    cin>>d;
    si = s-97;
    di= d-97;
    graph[si][di]=1;
    }
}

void print(int n)
{
    cout<<"The graph: \n";
    cout<<"  \t";
    for(int K=0;K<n;K++)
        {
            cout<<K<<"\t";
        }
        cout<<"\n_____________________________________________\n";

    for(int i=0;i<n;i++)
    {
        cout<<i<<"|\t";
        for(int j=0;j<n;j++)
            {
                cout<<graph[i][j]<<"\t";
            }
            cout<<endl;
    }
}
int main()
{
    int n;
    cout<<"Number of vertices: \n";
    cin>>n;
    initial(n);
    input();
    print(n);
}
