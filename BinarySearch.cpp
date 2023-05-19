#include<iostream>
using namespace std;

int insertionSort(int *array, int n)
{
    for(int i = 1;i<n;i++)
    {
        int j = i-1;
        int temp = array[i];
        while(array[j]>temp && j>=0)
        {
                array[j+1] = array[j];
                j--;

        }
        array[j+1]=temp;
    }

}

int BinarySearch(int *array, int low, int high, int key)
{
    if(low > high)
    {
        cout<<"No Such key"<<endl;
        return 0;
    }
    else
    {
        int mid = (low + high)/2;

        if(array[mid] == key)
        {
            cout<<"The key is founded!"<<endl;
        }
        else if(array[mid] < key)
        {
            return BinarySearch(array, mid+1, high, key);
        }
        else
        {
            return BinarySearch(array, low, mid-1, key);
        }
    }
}

void print(int *array, int arraySize)
{
    for(int i=0; i<arraySize; i++)
    {
        cout<<array[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
   int  array[] = {17,19,28,5,2,4,6};
   int arraySize = sizeof(array)/sizeof(int);
   int low=0;
   int high = arraySize-1;
   int key;


   insertionSort(array, arraySize);
   cout<<"After using insertion sort the array is :"<<endl;
   print(array, arraySize);

   cout<<"Enter the search key = ";
   cin>> key;
   cout<<endl;

   BinarySearch(array, low, high, key);

}

