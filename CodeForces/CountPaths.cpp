#include <cstdio>
#define MOD 1000000007

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int t[n][n], s[n][n], temp[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            t[i][j]=0;
            if (i==j)
                s[i][j]=1;
            else
                s[i][j]=0;
        }
    }
    for (int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        t[a-1][b-1]=1;
    }
    while (k>0)
    {
        if (k%2==1)
        {
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    temp[i][j]=0;
                }
            }
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    for (int k=0; k<n; k++)
                    {
                        temp[i][k]=(temp[i][k]+(long long)t[i][j]*s[j][k])%MOD;
                    }
                }
            }
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    s[i][j]=temp[i][j];
                }
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                temp[i][j]=0;
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                for (int k=0; k<n; k++)
                {
                    temp[i][k]=(temp[i][k]+(long long)t[i][j]*t[j][k])%MOD;
                }
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                t[i][j]=temp[i][j];
            }
        }
        k=k/2;
    }
    long long ans=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            ans=(ans+s[i][j])%MOD;
        }
    }
    printf("%lld\n", ans);
}