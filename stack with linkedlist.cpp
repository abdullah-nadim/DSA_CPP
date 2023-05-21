#include<bits/stdc++.h>
using namespace std;

struct node
    {
        int data;
        node *next=NULL;
    };
int n,item,top=0,maxSize=6;
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
void deleteLast()
    {
        currentNode=firstNode;
        while(currentNode->next!=NULL)
        {
        prevNode=currentNode;
        currentNode = currentNode->next;
        }
        prevNode->next=NULL;
        delete(currentNode);
    }
bool isfull()
{
    return(top==maxSize);
}
bool isEpmty()
{
    return (top==0);
}
void push(int element)
{
    if(isfull()==true)
    {
        cout<<"STACK IS OVERFLOWN\n";
    }
    else if(top==0)
    {
        createQueue(element);
        top++;
    }
    else
    {
        insertAtLast(element);
        top++;
    }
}
void pop()
{
    if(isEpmty())
    {
        cout<<"STACK IS EMPTY;";
    }
    else
    {
        deleteLast();
        top--;
    }
}
void show()
    {
        cout<<"The Stack:\n";
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
    cout<<"Enter the size of Stack:\n";
    cin>>maxSize;
    int y,ele;
    char ch='Y';
    while(ch == 'Y' || ch == 'y')
    {
     cout<<"What do you want to do?\n1. Push element in the stack\n2. Pop element from the stack \n3. Display the stack \n";
     cin>>y;
    switch(y)
    {
    case 2:
        pop();
        break;
    case 1:
        cout<<"Enter the element you want to push: \n";
        cin>>ele;
        push(ele);
        break;
    case 3:
        show();
        break;
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"Do you wanna continue?(y/n)\n";
    cin>>ch;
    }
}
