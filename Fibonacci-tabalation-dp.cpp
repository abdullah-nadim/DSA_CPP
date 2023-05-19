#include <iostream>

using namespace std;

int Fibonacci(int n)
{
    if(n<=1)
        return 0;

    int fib[n];
    fib[0]=0;
    fib[1]=1;

    for(int i =  2; i<n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n-1];
}

int main()
{
    cout<<Fibonacci(7);

    return 0;
}
