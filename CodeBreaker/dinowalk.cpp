#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int dist[n][n];
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (j!=k)
                {
                    if (i!=k && j!=i)
                        dist[j][k]=max(dist[j][k], min(dist[j][i],dist[i][k]));
                }
            }
        }
    }

    int ans=1e9;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            // printf("%d ", height[i][j]);
            if (i!=j)
                ans=min(ans, dist[i][j]);
        }
    }
    printf("%d\n", ans);
}