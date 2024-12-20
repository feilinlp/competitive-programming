#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int arr[n+1][n+1];
    for (int i=0; i<d; i++)
    {
        int x;
        scanf("%d", &x);
        int ar[x];
        for (int i=0; i<x; i++)
            scanf("%d", &ar[i]);
        for (int i=1; i<x; i++)
            arr[ar[i-1]][ar[i]]=1;
        arr[ar[x-1]][ar[0]]=1;
    }
    int ans[n+1];
    for (int i=1; i<n; i++)
        ans[i]=0;
    priority_queue <int> pq;
    pq.push(n);
    while (!pq.empty())
    {
        int x=pq.top();
        if (ans[x]!=1)
        {
            ans[x]=1;
        }
        else
        {
            continue;
        }
        pq.pop();
        for (int i=1; i<n; i++)
        {
            if (arr[i][x]==1 && arr[x][i]==1)
            {
                arr[i][x]=0;
                arr[x][i]=0;
            }
            else if (arr[i][x]==1)
            {
                pq.push(i);
            }
        }
    }
    for (int i=1; i<=n; i++)
        printf("%d ", ans[i]);
}