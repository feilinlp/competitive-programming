#include <cstdio>
#include <map>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int j=0; j<t; j++)
    {
        int n;
        scanf("%d", &n);
        map <int, int> m;
        int ans=0;
        for (int i=0; i<n; i++)
        {
            int x;
            scanf("%d", &x);
            if (m.count(x)==0)
                ans++;
            m[x]=1;
        }
        printf("%d\n", ans);
    }
}