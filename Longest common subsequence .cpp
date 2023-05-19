#include<iostream>
using namespace std;

int LcsLength(string x, string y,int m,int n)
{
    int c[m+1][n+1];
    for(int i=1;i<=m;i++)
        c[i][0]=0;

    for(int j=0;j<=n;j++)
        c[0][j]=0;

    for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(x[i-1]==y[j-1])
                {
                    c[i][j]=c[i-1][j-1]+1;
                }
                else if (c[i-1][j] >= c[i][j-1])
                {
                    c[i][j]= c[i-1][j];
                }
                else
                {
                    c[i][j]= c[i][j-1];
                }
            }
        }
        return c[m][n];
}

int main()
{
    string a = "BCDAACD";
    string b = "ACDBAC";
    int m = a.size();
    int n = b.size();

    cout<<"Length of LCS is ="<<LcsLength(a,b,m,n);
}

