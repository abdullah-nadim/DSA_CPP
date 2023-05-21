//insertion short
#include<iostream>
using namespace std;

int main()
{
    int n,cc=0,cs=0;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 1;i<n;i++)
    {
        int eoh = arr[i];
        for(int j =i-1;j>=0;j--)
        {
            int current_index =j;
            cc++;
            if(arr[current_index]>eoh)
            {
            arr[current_index+1]=arr[current_index];
            arr[current_index] = eoh;
            cs++;
            }

        }
    }
       for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    cout<<"Comapare: "<<cc<<endl;
    cout<<"Shifting: "<<cs<<endl;
}
