#include<iostream>
using namespace std;
int getposition(int arr[],int n)
{
    int siz = n;
    int item;
    cout<<"WHATS THE INTEGER: ";
    cin>>item;
    int position= -1;
    int f_index = 0;
    int l_index = siz-1;

   while(f_index<=l_index)
    {
        int m_index =(f_index+l_index)/2;
        if(arr[m_index]>item)
        {
            l_index = m_index-1;
        }
        else if(arr[m_index]<item)
        {
            f_index = m_index+1;

        }
        else
        {
            position = m_index;
            break;
        }
    }
    if(position==-1)
    {
        cout<<"Not found";
    }
    else{
    cout<<"POSITION: "<<position;
    }
}
int main()
{
   int n;
    cout<<"Enter Array size: "<<endl;
    cin>>n;
    cout<<"Enter Array Elements:\n";
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i = 0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i]=temp;
            }
        }
    }
    getposition(arr,n);
}

