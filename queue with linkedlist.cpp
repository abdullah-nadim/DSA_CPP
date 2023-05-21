#include<bits/stdc++.h>
using namespace std;

struct node
    {
        int data;
        node *next=NULL;
    };
    int n,item,front=-1,rear=-1,maxSize;
    node *currentNode, *newNode,*prevNode;
    node *firstNode ;

void createNode(int value)
    {
        newNode=new(node);
        newNode->data = value;
        newNode->next=NULL;

    }
void createQueue(int value)
{
    firstNode = NULL;
    createNode(value);
    if(firstNode==NULL)
            {
                firstNode=newNode;
                currentNode = newNode;
            }
}

void insertAtLast(int value)
    {
        currentNode=firstNode;
        createNode(value);
        while(currentNode->next!=NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next=newNode;
    }
void deleteFirst()
    {
        currentNode=firstNode;
        firstNode=firstNode->next;
        delete(currentNode);
    }
void deleteQueue()
    {
       currentNode=firstNode;
       while(currentNode->next!=NULL)
        {
            deleteFirst();
            currentNode = currentNode->next;
        }
    }

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
        if(rear == maxSize-1)
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
            createQueue(element);
            return true;
        }
        else
        {
            rear++;
            insertAtLast(element);
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
            deleteQueue();
            return true;
        }
        else
        {
            front++;
            deleteFirst();
        }
    }
    void showQueue()
    {
        cout<<"The Queue:\n";
        currentNode = firstNode;
        while(currentNode!=NULL)
        {
            cout<<currentNode->data;
            currentNode = currentNode->next;
            cout<<" ";
        }
         cout<<endl;
    }



int main()
{
    cout<<"Enter the size of Queue:\n";
    cin>>maxSize;
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
        enqueue(ele);
        break;
    case 2:

        dequeue();
        break;
    case 3:
        showQueue();
        break;
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"Do you wanna continue?(y/n)\n";
    cin>>ch;
    }
}
