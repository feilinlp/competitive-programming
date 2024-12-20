#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[500001], powerparent[500001][19];
vector <int> connect[500001];
int n;

void dfs(int x=0)
{
    powerparent[x][0]=parent[x];
    for (int i=1; i<19; i++)
    {
        if (powerparent[x][i-1]==-1)
            break;
        powerparent[x][i]=powerparent[powerparent[x][i-1]][i-1];
        //printf("powerparent[%d][%d] = %d\n", x, i, powerparent[x][i]);
    }
    for (int y:connect[x])
    {
        if (y!=0 && parent[y]==-1)
        {
            parent[y]=x;
            dfs(y);
        }
    }
}

int lca(int x, int k)
{
    for (int i=18; i>=0; i--)
    {
        if (k>>i&1 == 1)
        {
            //printf("x k = %d %d\n", x, k);
            //printf("%d\n", powerparent[x][k]);
            x=powerparent[x][i];
            if (x==-1)
                return x;
        }
    }
    return x;
}

int main()
{
    scanf("%d", &n);
    parent[0]=-1;
    for (int i=0; i<500001; i++)
    {
        parent[i]=-1;
        for (int j=0; j<19; j++)
            powerparent[i][j]=-1;
    }
    for (int i=1; i<n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        connect[a].push_back(b);
        connect[b].push_back(a);
    }
    dfs();
    int q;
    scanf("%d", &q);
    for (int i=0; i<q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
}