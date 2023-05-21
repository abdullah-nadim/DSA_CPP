#include<iostream>
using namespace std;

struct node
    {
        int data;
        node *next=NULL;
    };
int main()
{

    int value,n,item;
    node *tptr, *nptr,*pptr;
    node *list = NULL;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>value;
        nptr = new(node);
        nptr->data= value;
        nptr->next= NULL;
        if(list==NULL)
        {
            list=nptr;
            tptr = nptr;
        }
        else
        {
            tptr->next=nptr;
            tptr = nptr;
        }
    }

    tptr = list;
    for(int i=1;i<=n;i++)
    {
        cout<<endl;
        cout<<tptr-> data;
        tptr = tptr->next;
        cout<<" ";
    }
    cout<<endl;


    cin>>value;
   nptr = new(node);
   nptr->data = value;
   nptr->next=list;
   list= nptr;

    cout<<"last  ";
   cin>>value;
   tptr=list;
   nptr=new(node);
   nptr->data = value;
   nptr->next=NULL;
   while(tptr->next!=NULL)
    {
        tptr = tptr->next;
    }
    cout<<"dd"<<tptr->data<<endl;;
    tptr->next=nptr;


    cout<<"last  ";
   cin>>value>>item;
   tptr=list;
   nptr=new(node);
   nptr->data = value;
   nptr->next=NULL;
   while(tptr->data!=item)
    {
        tptr = tptr->next;
    }
    nptr->next=tptr->next;
    tptr->next=nptr;






    tptr=list;
    list=list->next;
    delete(tptr);

    cin>>value;
    tptr=list;
    while(tptr->data!=value)
    {
        pptr=tptr;
        tptr = tptr->next;
    }
    pptr->next=tptr->next;
    delete(tptr);

    tptr=list;
    while(tptr->next!=NULL)
    {
        pptr=tptr;
        tptr = tptr->next;
    }
    pptr->next=NULL;
    delete(tptr);

    cout<<"show:\n";
    tptr = list;
    while(tptr!=NULL)
    {
        cout<<endl;
        cout<<tptr-> data;
        tptr = tptr->next;
        cout<<" ";
    }



}
