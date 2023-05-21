#include<iostream>
using namespace std;

struct node
    {
        int sId;
        string name;
        char grade;
        node *next=NULL;
    };
    int value,n,item,id;
    string nam;
    char grd;
    node *currentNode, *newNode,*prevNode;
    node *firstNode ;
void newNodef()
    {
        newNode=new(node);
        newNode->sId = id;
        newNode->name = nam;
        newNode->grade= grd;
        newNode->next=NULL;

    }
void createNode()
    {
      firstNode = NULL;
        cout<<"Enter firstNode size: \n";
        cin>>n;
        cout<<"_______Enter Student info_____\n";
        for(int i=1;i<=n;i++)
        {
            cout<<"Enter student id: \n";
            cin>>id;
            cout<<"Enter student name: \n";
            cin>>nam;
            cout<<"Enter student grade: \n";
            cin>>grd;
            newNodef();
            if(firstNode==NULL)
            {
                firstNode=newNode;
                currentNode = newNode;
            }
            else
            {
                currentNode->next=newNode;
                currentNode = newNode;
            }
        }
    }
void insertAtLast()
    {
        cout<<"Enter student id: \n";
            cin>>id;
            cout<<"Enter student name: \n";
            cin>>nam;
            cout<<"Enter student grade: \n";
            cin>>grd;
        currentNode=firstNode;
        newNodef();
        while(currentNode->next!=NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next=newNode;
    }
void insertAtMiddle()
    {
        cout<<"Enter student id: \n";
            cin>>id;
            cout<<"Enter student name: \n";
            cin>>nam;
            cout<<"Enter student grade: \n";
            cin>>grd;
        cout<<"WHere do yoou wanna add?\n";
        cin>>item;
        currentNode=firstNode;
        newNodef();
        while(currentNode->sId!=item)
        {
            currentNode = currentNode->next;
        }
        newNode->next=currentNode->next;
        currentNode->next=newNode;
    }
void insertAtFirst()
    {
            cout<<"Enter student id: \n";
            cin>>id;
            cout<<"Enter student name: \n";
            cin>>nam;
            cout<<"Enter student grade: \n";
            cin>>grd;
            newNodef();
        newNode->next=firstNode;
        firstNode= newNode;
    }
void deleteFirst()
    {
        currentNode=firstNode;
        firstNode=firstNode->next;
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
        cout<<"Enter the student id you wanna delete:\n";
        cin>>value;
        currentNode=firstNode;
        while(currentNode->sId!=value)
        {
            prevNode=currentNode;
            currentNode = currentNode->next;
        }
        prevNode->next=currentNode->next;
        delete(currentNode);
    }
void searchNode()
    {
        cout<<"Enter the student id you wanna Search:\n";
        cin>>id;
        bool flag = false;
        currentNode=firstNode;
        while(currentNode->sId!=id)
        {
            currentNode = currentNode->next;

        }
        if(currentNode->sId==id)
                flag=true;
        if(flag)
        {
            cout<<"Student found";
        }
        else
            cout<<"NOT FOUND";
    }
void show()
    {
        cout<<"The linked firstNode:";
        currentNode = firstNode;
        while(currentNode!=NULL)
        {
            cout<<endl;
            cout<<currentNode-> sId;
            cout<<currentNode->name;
            cout<<currentNode->grade;
            currentNode = currentNode->next;
            cout<<" ";
        }
    }
int main()
{
    int y;
    char ch='Y';
    while(ch == 'Y' || ch == 'y')
    {
     cout<<"What do you want to do?\n1. Create new node \n2. Insert element at first\n3. Insert element at last \n4. Insert element after a number \n5. Search Student\n6. Delete last node \n7. Delete specific node \n8. Display the LINKED LIST \n";
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
        searchNode();
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
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"\nDo you wanna continue?(y/n)\n";
    cin>>ch;
    }

}
