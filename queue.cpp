#include<iostream>
using namespace std;

class MyQueue{
int Queue[4];
int maxSize=4;
int front =-1,rear=-1;
public:
    bool isEmpty()
    {
        if(front == -1&& rear==-1)
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
        if(((rear+1)%maxSize)== front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool enqueue (int element)
    {
        if(isFull()== true)
        {
            cout<<"QUEUE IS FULL!\n";
        }
        else if( isEmpty()== true)
        {
            front=rear=0;
            Queue[rear]=element;
            return true;
        }
        else
        {
            rear=(rear+1)%maxSize;
            Queue[rear]=element;
        }
    }
    bool dequeue()
    {
        if(isEmpty()==true)
        {
            cout<<"STACK IS EMPTY;";
            return false;
        }
        else if(front==rear)
        {
            front=rear=-1;
            return true;
        }
        else
        {
            front=(front+1)%maxSize;
        }
    }
    void showQueue()
    {
        if(isEmpty())
            {
                cout<<"";
            }

        else{
          cout<<"The queue is:"<<endl;
         if(front<=rear)
        {
            for(int i = front;i<=rear;i++)
            {
                cout<<Queue[i]<<"\t";
            }
        }
        else
        {
            for(int i = front; i<=(maxSize-1);i++)
            {
                cout<<Queue[i]<<"\t";
            }
            for(int i = 0;i<=rear;i++)
            {
                cout<<Queue[i]<<"\t";
            }
        }
        }
    }
};

int main()
{
    MyQueue x;
    int y,ele;
    char ch='Y';
    while(ch == 'Y' || ch == 'y')
    {
        cout<<"What do you want to do?\n1. Enqueue element in the stack\n2. Dequeue element from the stack \n3. Display the Queue \n";
    cin>>y;
    switch(y)
    {
    case 1:
        cout<<"Enter the element you want to enqueue: \n";
        cin>>ele;
        x.enqueue(ele);
        break;
    case 2:

        x.dequeue();
        break;
    case 3:
        x.showQueue();
        break;
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"Do you wanna continue?(y/n)\n";
    cin>>ch;
    }
}
