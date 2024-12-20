#include <cstdio>

using namespace std;

int main()
{
    int n, l, t;
    scanf("%d %d %d", &n, &l, &t);
    int f[n];
    for (int i=0; i<n; i++)
        scanf("%d", &f[i]);
    int ans=0;
    bool yes=true;
    int pos=0;
    int curr=0;
    while (pos<l && yes==true)
    {
        if (curr==n)
        {
            if (l-pos>t && pos==f[n-1])
                yes=false;
            else
            {
                if (l-pos>t)
                    ans++;
            }
            break;
        }

        if (f[curr]-pos>t && pos==f[curr-1])
            yes=false;
        else
        {
            if (f[curr]-pos>t)
            {
                pos=f[curr-1];
                ans++;
            }
            else
                curr++;
        }
    }
    if (yes==true)
        printf("%d\n", ans);
    else
        printf("-1\n");
}