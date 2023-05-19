#include<iostream>
using namespace std;

int MatrixChainOrder(int n, int *a)
{
    int M[n][n];
    int s[n][n];

    for(int i=0;i<n;i++)
    {
        M[i][i]=0;
        s[i][i]=0;

    }

        for(int len=2; len<n;len++)
        {
            for(int i=1;i<n-len+1;i++)
            {
                int j= i+len-1;
                M[i][j]= INT_MAX;
                for(int k=i;k<=j-1;k++)
                {
                    int q=M[i][k]+M[k+1][j]+a[i-1]*a[k]*a[j];
                    if(q<M[i][j])
                    {
                        M[i][j]=q;
                        s[i][j]=k;
                    }
                }
            }
        }
        return M[1][n-1];

}

int main()
{
    int a[]= {1,2,3,4};
    int n= sizeof(a)/sizeof(int);
    cout<<MatrixChainOrder(n,a);

}
