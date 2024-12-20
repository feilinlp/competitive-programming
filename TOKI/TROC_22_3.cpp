#include <cstdio>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n];
    scanf("%c", &s);
    int val[k+1][k+1];
    for (int i=1; i<=k; i++)
    {
        for (int j=1; j<=k; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }
    int ans=0;
    int rem[n];
    for (int i=1; i<n-1; i++)
    {
        rem[i]=val[s[i-1]][s[i]] + val[s[i]][s[i+1]] - val[s[i-1]][s[i+1]];
    }
}