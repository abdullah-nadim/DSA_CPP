#include<iostream>
using namespace std;

const int n =100;
int cost[n][n];

int min_Key(int key[], int visited[],int ver)
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < ver; i++) {
        if (visited[i] == 0 && key[i] < min) {
            min = key[i];
			min_index = i;
        }
    }
    return min_index;
}


int print_MST(int parent[], int ver)
{
    int minCost=0;
	cout<<"Edge \tWeight\n";
    for (int i = 1; i< ver; i++) {
		cout<<parent[i]<<" - "<<i<<" \t"<<cost[i][parent[i]]<<" \n";
		minCost+=cost[i][parent[i]];
    }
	cout<<"Total cost is"<<minCost;
}

void find_MST(int ver)
{
    int parent[ver], key[ver];
    int visited[ver];

    for (int i = 0; i< ver; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
        parent[i]=-1;
    }

    key[0] = 0;  // Include first vertex in MST by setting its key vaue to 0.

    // The MST will have maximum V-1 vertices
    for (int i = 0; i < ver - 1; i++)
    {
        // Finding the minimum key vertex from the
        //set of vertices not yet included in MST
        int j = min_Key(key, visited,ver);

        visited[j] = 1;  // Add the minimum key vertex to the MST

        // Update key and parent arrays
        for (int k = 0; k < ver; k++)
        {
            // cost[u][v] is non zero only for adjacent vertices of u
            // visited[v] is false for vertices not yet included in MST
            // key[] gets updated only if cost[u][v] is smaller than key[v]
            if (cost[j][k]!=0 && visited[k] == 0 && cost[j][k] < key[k])
            {
                parent[k] = j;
                key[k] = cost[j][k];
            }
        }
    }

    // print the final MST
	print_MST(parent, ver);
}

int main()
{

    int edg,ver,wght,st,en;
    cout <<"Enter no of vertices:"<<endl;
    cin >> ver;
    cout <<"Enter no of edges:"<<endl;
    cin >> edg;
    for(int i=0; i<edg;i++)
    {
        cout <<"Enter the start and end vertex of the edges and weight: "<<endl;
        cin>>st>>en>>wght;
        cost[st][en]=wght;
        cost[en][st]=wght;
    }

    find_MST(ver);

}
