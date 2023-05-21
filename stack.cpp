#include<iostream>
using namespace std;

class MyStack{
int maxSize=3;
int *Stack = new int [maxSize];
int top = 0;

public:
    bool isEmpty()
    {
        if(top == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if(top == maxSize)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool push(int element)
    {
        if(isFull()== true)
        {
            cout<<"STACK OVERFLOWED\n";
            resize();
            Stack[top++]=element;
            return true;
        }
        else
        {
        Stack[top]=element;
        top++;
        return true;
        }
    }
    bool pop()
    {
        if(isEmpty()==true)
        {
            cout<<"STACK IS EMPTY;";
            return false;
        }
        else
        {
            top--;
            return true;
        }
    }
    void show()
    {
        for(int i = top-1;i>=0;i--)
        {
            cout<<Stack[i]<<endl;
        }
    }
    void resize(int size=2)
    {
        int *tempStk = new int [maxSize+size];
        for(int i=0;i<maxSize;i++)
        {
            tempStk[i] = Stack[i];
        }
        maxSize+=size;
        delete [] Stack;
        Stack = tempStk;
    }
};

int main()
{
     MyStack x;
     int y,ele;
     char ch='Y';
    while(ch == 'Y' || ch == 'y')
    {
     cout<<"What do you want to do?\n1. Push element in the stack\n2. Pop element from the stack \n3. Display the stack \n";
     cin>>y;
    switch(y)
    {
    case 2:
        x.pop();
        break;
    case 1:
        cout<<"Enter the element you want to push: \n";
        cin>>ele;
        x.push(ele);
        break;
    case 3:
        x.show();
        break;
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"Do you wanna continue?(y/n)\n";
    cin>>ch;
    }
}
