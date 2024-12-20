#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &a[0][i]);
    }
    for (int i=1; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
            if (j==0)
                a[i][j]+=max(a[i-1][j], a[i-1][j+1]);
            else if (j==n-1)
                a[i][j]+=max(a[i-1][j], a[i-1][j-1]);
            else
                a[i][j]+=max(a[i-1][j], max(a[i-1][j-1], a[i-1][j+1]));
        }
    }
    int ans=0;
    for (int i=0; i<n; i++)
    {
        ans=max(ans, a[m-1][i]);
    }
    printf("%d\n", ans);
}