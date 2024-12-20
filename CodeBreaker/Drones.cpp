#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    vector <int> ans(n+1, 0);
    vector < vector <int> > connected(n+1); //work backwords connected[destination][start]
    for (int i=1; i<=n; i++)
    {
        connected[i].resize(n+1, 0);
    }
    for (int i=0; i<d; i++)
    {
        int x;
        scanf("%d", &x);
        vector <int> temp(x);
        for (int j=0; j<x; j++)
        {
            scanf("%d", &temp[j]);
            if (j>0)
            {
                if (connected[temp[j-1]][temp[j]]==0)
                    connected[temp[j]][temp[j-1]] = 1;
                else
                {
                    connected[temp[j-1]][temp[j]] = -1;
                    connected[temp[j]][temp[j-1]] = -1;
                }
            }
        }
        if (connected[temp[x-1]][temp[0]]==0)
            connected[temp[0]][temp[x-1]] = 1;
        else
        {
            connected[temp[x-1]][temp[0]] = -1;
            connected[temp[0]][temp[x-1]] = -1;
        }
    }

    queue <int> visit;
    visit.push(n);
    while (!visit.empty())
    {
        int x = visit.front();
        ans[x] = 1;
        visit.pop();
        for (int i=1; i<=n; i++)
        {
            if (ans[i] != 1 && connected[x][i]==1)
            {
                visit.push(i);
            }
        }
    }

    for (int i=1; i<=n; i++)
        printf("%d ", ans[i]);
    printf("\n");
}