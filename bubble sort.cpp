 //Bubble sort
#include<iostream>
using namespace std;

int main()
{
    int n,cs=0,cc=0;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 0;i<n-1;i++)
    {
      int starting_index= i;
      cout<<"phase: "<<i+1<<endl;
     for (int j=0;j<(n-1)-i;j++)
     {
         int current_index=j;
         cc++;
         if(arr[current_index]>arr[current_index+1])
         {
           int temp = arr[current_index+1];
                arr[current_index+1] = arr[current_index];
                arr[current_index]=temp;
                cs++;

         }

         for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
        cout<<"\n";
     }

    }
    for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    cout<<"Comapare: "<<cc<<endl;
    cout<<"Swap: "<<cs<<endl;
}
