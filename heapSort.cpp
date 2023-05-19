#include<iostream>
using namespace std;

void heapify(int *arr,int n,int p)
{
    int largest = p;

    int l = 2*p+1;
    int r = 2*p+2;

    if(l<n && arr[largest]<arr[l])
        largest=l;

    if(r<n && arr[largest]<arr[r])
        largest=r;

    if(largest!=p)
        swap(arr[largest],arr[p]);

    if(p<n)
        heapify(arr ,n, p+1 );
}

void HeapSort(int *arr,int n)
{
    heapify(arr,n,0);
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = { 12,32,65, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
    HeapSort(arr, N);
    cout << "Sorted array is \n";
    printArray(arr, N);
}

