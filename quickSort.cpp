#include<iostream>
using namespace std;
static int c = 0;

void swap(int* a, int* b)
{
    int t = *a;
    *a =*b;
    *b = t;
    c++;
}

int partition(int arr[],int start,int end)
{
    int pivot = arr[end];
    int i = start;
   // cout<<i<<"check/n";
    for(int j= start; j<=end-1;j++)
    {
        if(arr[j]<=pivot)
        {

            swap(&arr[i],&arr[j]);
            i++;

        }
    }
    swap(&arr[i],&arr[end]);
    return (i);
}

void quicksort(int arr[],int start, int r)
{
    if(start<r)
    {
        int q= partition(arr,start,r);
        quicksort(arr,start,q-1);
        quicksort(arr,q+1,r);
    }
}
void print(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Array size: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i<n;i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"sorted array: ";
    print(arr,n);
    cout<<"swap:"<<c;
}
