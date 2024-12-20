#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n, m, l, r;
    scanf("%d %d %d %d", &n, &m, &l, &r);
    vector <int> visited(m+1), value(m);
    for (int i=0; i<=m; i++)
        visited[i]=0;
    int diff=0;
    for (int i=1; i<=n; i++)
    {
        int x;
        scanf("%d", &x);
        if (visited[x]==0)
        {
            diff++;
            visited[x]++;
        }
    }
    long long pref=0;
    for (int i=1; i<n; i++)
    {
        scanf("%d", &value[i]);
        pref+=value[i];
    }
    if (diff!=m)
        printf("-1\n");
    else
        printf("%lld\n", pref);
}