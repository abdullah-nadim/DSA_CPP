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
    for(int d=2;d<n;d++)
    {
        for(int i=1;i<n-d+1;i++)
        {
            int j= d+i-1;
            M[i][j]= INT_MAX;
            for(int k=i;k<j;k++)
            {
                int val = M[i][k]+M[k+1][j]+a[i-1]*a[k]*a[j];
                if(M[i][j]>val)
                {
                    M[i][j]=val;
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
