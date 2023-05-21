#include<iostream>
using namespace std;

struct node
    {
        int data;
        node *next=NULL;
        node *pre=NULL;
    };
 int value,item,n;
 node *tptr, *pptr, *ptr, *list;

void newNodef()
    {
        ptr=new(node);
        ptr->data= value;
        ptr->pre=NULL;
        ptr->next=NULL;
    }
void createNode()
 {
        list = NULL;
        cout<<"Enter list size: \n";
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cout<<"Enter value: \n";
            cin>>value;
            newNodef();
            if(list==NULL)
            {
                list=ptr;
                tptr = ptr;
            }
            else
            {
                ptr->next= list;
                ptr->pre=tptr;
                tptr->next=ptr;
                tptr = ptr;
                list->pre=tptr;
            }
        }
}
void insertAtFirst()
    {
        cout<<"Enter the element you want to add:\n";
        cin>>value;
        ptr = new(node);
        ptr->data = value;
        ptr->next=list;
        ptr->pre=list->pre;
        list->pre->next=ptr;
        list->pre=ptr;
        list= ptr;
    }
void insertAtMiddle()
    {
        cout<<"Enter the element you want to add: \n";
        cin>>value;
        cout<<"WHere do you wanna add?\n";
        cin>>item;
        tptr=list;
        newNodef();
        while(tptr->data!=item)
        {
            tptr = tptr->next;
        }
        tptr->next->pre=ptr;
        ptr->next=tptr->next;
        ptr->pre=tptr;
        tptr->next=ptr;
    }
void insertAtLast()
{
        cout<<"Enter the element you want to add: \n";
        cin>>value;
        tptr=list;
        newNodef();
        while(tptr->next!=list)
        {
            tptr = tptr->next;
        }
        tptr->next->pre=ptr;
        ptr->next=tptr->next;
        ptr->pre=tptr;
        tptr->next=ptr;
}
void deleteNode()
    {
        cout<<"Enter the the value you wanna delete:\n";
        cin>>value;
        tptr=list;
        while(tptr->data!=value)
        {
            pptr=tptr;
            tptr = tptr->next;
        }
        pptr->next=tptr->next;
        tptr->next->pre=pptr;
        delete(tptr);
    }
void deleteFirst()
    {
        tptr=list;
        list=list->next;
        list->pre=tptr->pre;
        tptr->pre->next=list;
        delete(tptr);
    }
void deleteLast()
    {
        tptr=list;
        while(tptr->next!=list)
        {
            pptr=tptr;
            tptr = tptr->next;
        }
        pptr->next=tptr->next;
        tptr->next->pre=pptr;
        delete(tptr);
    }
void show()
    {
        cout<<"The list:\n";
        tptr = list;
        while(tptr->next!=list)
        {
            cout<<tptr->data;
            tptr = tptr->next;
            cout<<endl;
        }
        cout<<tptr->data<<endl;
    }
int main()
{
    int y;
    char ch='Y';
    while(ch == 'Y' || ch == 'y')
    {
     cout<<"What do you want to do?\n1. Create new node \n2. Insert element at first\n3. Insert element at last \n4. Insert element after a number \n5. Delete first node\n6. Delete last node \n7. Delete specific node \n8. Display the LINKED LIST \n";
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
    default:
        cout<<"Invalid Input\n";
    }
    cout<<"\nDo you wanna continue?(y/n)\n";
    cin>>ch;
    }
}
