#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct cow{
    int c, t;
};

bool comp(cow a, cow b)
{
    return a.c<b.c;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector <cow> v(n);
    map <int, int> p;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &v[i].c, &v[i].t);
        if (p[v[i].t]==NULL)
            p[v[i].t]=0;
    }
    sort(v.begin(), v.end(), comp);
    int left=0, right=0, ans=1e9, no=0;
    while (right<=n)
    {
        if (no<p.size())
        {
            p[v[right].t]++;
            if (p[v[right].t]==1)
                no++;
            right++;
        }
        else
        {
            //printf("%d %d", left, right);
            ans=min(ans, v[right-1].c-v[left].c);
            p[v[left].t]--;
            if (p[v[left].t]==0)
                no--;
            left++;
        }
    }
    printf("%d\n", ans);
}