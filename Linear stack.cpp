#include<iostream>
using namespace std;

class MyStack{
int Stack[100];
int top =0;
int maxSize=6;
public:
    void push(int element)
{
    if(isfull()==true)
    {
        cout<<"STACK IS OVERFLOWN\n";
    }
    else
    {
        Stack[top]=element;
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
        top--;
    }
}
bool isfull()
{
    return(top==maxSize);
}
bool isEpmty()
{
    return (top==0);
}
void show()
{
    for(int i = top-1;i>=0;i--)
    {
        cout<<Stack[i]<<endl;
    }
}
};

int main()
{
    MyStack x;
    x.push(2);
    x.push(3);
    x.push(5);
    x.pop();
    x.push(1);
    x.pop();
    x.push(8);
    x.push(4);
    x.pop();
    x.pop();
    x.pop();
    x.show();
}
