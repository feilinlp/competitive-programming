#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector < pair <int, int> > ppl(n);
    for (int i=0; i<n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        ppl[i].first=a-b;
        if (a-b<0)
            ppl[i].first=0;
        ppl[i].second=a+b;
        if (a+b>m)
            ppl[i].second=m;
    } 
    sort(ppl.begin(), ppl.end());

    pair <int, int> need;
    need.first=m+1;
    need.second=-1;
    int count=0;
    for (int i=0; i<n; i++)
    {
        if (ppl[i].first>need.second)
        {
            count++;
            need=ppl[i];
        }
        else
        {
            need.first=max(need.first, ppl[i].first);
            need.second=min(need.second, ppl[i].second);
        }
    }
    printf("%d\n", count);
}