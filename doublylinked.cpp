#include<iostream>
using namespace std;

struct node
    {
        int data;
        node *next=NULL;
        node *back=NULL;
    };
    int value,n,item;
    node *currentNode, *newNode,*prevNode;
    node *firstNode ;
void newNodef()
    {
        newNode=new(node);
        newNode->data= value;
        newNode->back=NULL;
        newNode->next=NULL;
    }
void createNode()
{

        firstNode = NULL;
        cout<<"Enter firstNode size: \n";
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cout<<"Enter student id: \n";
            cin>>value;
            newNodef();
            if(firstNode==NULL)
            {
                firstNode=newNode;
                currentNode = newNode;
            }
            else
            {
                newNode->back=currentNode;
                currentNode->next=newNode;
                currentNode = newNode;
            }
        }
}
void insertAtFirst()
    {
        cout<<"Enter value of node\n";
        cin>>value;
        newNode = new(node);
        newNode->data = value;
        newNode->next=firstNode;
        firstNode->back=newNode;
        firstNode= newNode;
    }
void insertAtMiddle()
    {
        cout<<"Enter the element you want to add: \n";
        cin>>value;
        cout<<"WHere do you wanna add?\n";
        cin>>item;
        currentNode=firstNode;
        newNodef();
        while(currentNode->data!=item)
        {
            currentNode = currentNode->next;
        }
        newNode->next=currentNode->next;
        newNode->back=currentNode;
        currentNode->next=newNode;
    }
    void insertAtLast()
    {
        cout<<"Enter the element you want to add: \n";
        cin>>value;
        currentNode=firstNode;
        newNodef();
        while(currentNode->next!=NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next=newNode;
        newNode->back=currentNode;
    }
    void deleteFirst()
    {
        currentNode=firstNode;
        firstNode=firstNode->next;
        firstNode->back=NULL;
        delete(currentNode);
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
    void deleteNode()
    {
        cout<<"Enter the the value you wanna delete:\n";
        cin>>value;
        currentNode=firstNode;
        while(currentNode->data!=value)
        {
            prevNode=currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next=currentNode->next;
        currentNode->next->back=prevNode;
        delete(currentNode);
    }
    void show()
    {
        cout<<"The linked firstNode:";
        currentNode = firstNode;
        while(currentNode!=NULL)
        {
            cout<<endl;
            cout<<currentNode->data;
            currentNode = currentNode->next;
            cout<<" ";
        }
    }
void showBackNode()
{
    cout<<"Enter the the value :\n";
        cin>>value;
        currentNode=firstNode;
        while(currentNode->data!=value)
        {
          currentNode = currentNode->next;
        }
        cout<<"BackNODE: "<<currentNode->back->data;
}
    int main()
{
    int y;
    char ch='Y';
    while(ch == 'Y' || ch == 'y')
    {
     cout<<"What do you want to do?\n1. Create new node \n2. Insert element at first\n3. Insert element at last \n4. Insert element after a number \n5. delete first node\n6. Delete last node \n7. Delete specific node \n8. Display the LINKED LIST \n9. display Back node.\n";
     cin>>y;
    switch(y)
    {
    case 1:
        createNode();
        break;
    case 2:
        insertAtFirst();
        break;
    case 3:
        insertAtLast();
        break;
    case 4:
        insertAtMiddle();
        break;
    case 5:
        deleteFirst();
        break;
    case 6:
        deleteLast();
        break;
    case 7:
        deleteNode();
        break;
    case 8:
        show();
        break;
    case 9:
        showBackNode();
        break;
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"\nDo you wanna continue?(y/n)\n";
    cin>>ch;
    }

}
