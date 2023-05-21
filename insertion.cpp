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
        int j = i-1;
        int temp = arr[i];
        while(arr[j]>temp && j>=0)
        {
                cc++;
                arr[j+1] = arr[j];
                j--;
                cs++;

        }
         arr[j+1]=temp;
     /*  for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    */}
        for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    cout<<"Comapare: "<<cc<<endl;
    cout<<"Swap: "<<cs<<endl;

}
