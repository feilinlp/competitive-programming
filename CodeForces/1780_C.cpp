#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        vector <int> fav(n+1, 0);
        for (int i=0; i<n; i++)
        {
            int x;
            scanf("%d", &x);
            fav[x]++;
        }
        priority_queue <int> dish, table;
        for (int i=0; i<m; i++)
        {
            int x;
            scanf("%d", &x);
            table.push(x);
        }
        for (int i=0; i<=n; i++)
        {
            dish.push(fav[i]);
        }

        int ans=0;
        while (!table.empty() && !dish.empty())
        {
            int t=table.top(), d=dish.top();
            table.pop();
            dish.pop();
            if (t>=d)
            {
                ans+=d;
            }
            else
            {
                ans+=t;
                dish.push(d-t);
            }
        }
        printf("%d\n", ans);
    }
}