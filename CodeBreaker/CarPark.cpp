#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

bool comp(int a, int b)
{
    if (a==0)
        return false;
    else if (b==0)
        return true;
    else
        return a<b;
}

int main()
{
    int n, s;
    int d=0;
    scanf("%d %d", &n, &s);
    int v[n];
    memset(v, 0, sizeof(v));
    int x, pos=-1;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if (pos==-1)
        {
            if (x==1)
            {
                pos++;
                d++;
                ans++;
            }
        }
        else
        {
            if (x==0)
            {
                v[pos]++;
            }
            else
            {
                if (v[pos]!=0)
                {
                    pos++;
                    d++;
                }
                
                ans++;
            }
        }
    }
    if (x!=1)
        v[pos]=0;
    sort(v, v+n, comp);
    for (int i=0; i<d-s; i++)
    {
        ans+=v[i];
    }
    printf("%d\n", ans);
}