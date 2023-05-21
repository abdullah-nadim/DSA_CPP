#include<iostream>
#include <cstring>
using namespace std;



class Postfix
{
    char Stack[100];
    int top =0;
    string pst;
public:
    bool isEpmty()
     {
         if(top==0)
         {
            return true ;
         }
         else
         {
             return false;
         }
     }
    void push(char element)
    {
            Stack[top]=element;
            top++;
    }
     void pop()
    {
        if(!isEpmty())
        {
            top--;
        }
    }
    int prd(char op)
    {
        if(op=='+' || op=='-')
        {
            return 1;
        }
        else if(op=='/' || op=='*')
        {
            return 2;
        }
        else if(op=='^')
        {
            return 3;
        }
        return 0;
    }
void pstfx(string infix)
{
    int size = infix.size();
    //cout<<"s:"<<size<<endl;
    int i=0;
    while(i<size)
    {
        //cout<<i;
        if(infix[i]>='a' && infix[i]<='z'||infix[i]>='A' && infix[i]<='Z')
        {
            pst+= infix[i];
        }
        else if(infix[i]=='('||infix[i]=='{'||infix[i]=='[')
                    {
                       push(infix[i]);
                    }
        else if(infix[i]=='-'||infix[i]=='+'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            if(top==0)
            {
                push(infix[i]);
            }
            else if(Stack[top-1]=='('||Stack[top-1]=='{'||Stack[top-1]=='[')
                    {
                       push(infix[i]);
                    }
            else if (Stack[top-1]=='-'||Stack[top-1]=='+'||Stack[top-1]=='*'||Stack[top-1]=='/'||Stack[top-1]=='^')
            {
                if(prd(infix[i])<=prd(Stack[top-1]))
            {
                pst += Stack[top-1];
                pop();
            }
            else if(prd(infix[i])>prd(Stack[top-1]))
            {
                push(infix[i]);
            }
            }
        }
        else if(infix[i]==')'||infix[i]=='}'||infix[i]==']')
        {

            while(top>1 && (Stack[top-1]!='('||Stack[top-1]!='{'||Stack[top-1]!='['))
                    {
                        pst += Stack[top-1];
                        pop();



                   }
                pop();
        }
    ++i;
    }
    while(top!=0)
    {

        pst += Stack[top-1];
        pop();
    }



}
void show()
{
    cout<<pst;
}
};



int main()
{
    Postfix p;
    string inf = "a+(b*c)"  ;
    p.pstfx(inf);
    p.show();
}
