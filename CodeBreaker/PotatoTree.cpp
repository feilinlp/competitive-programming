#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    vector <int> a(n);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    vector <pair<int, int>> l(q);
    //vector <int> b;
    map <int, int> b; 
    vector <int> ans(q);
    for (int i=0; i<q; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        l[i]=make_pair(x, i);
    }
    sort(l.begin(), l.end());
    int i=0;
    int diff=0;
    int pos=0;
    while (pos<q)
    {
        if (b[a[i]]!=1)
        {
            b[a[i]]=1;
            diff++;
        }
        if (i==l[pos].first)
        {
            diff=b.size();
            ans[l[pos].second]=diff;
            pos++;
        }
        i++;
    }
    for (int i=0; i<q; i++)
        printf("%d ", ans[i]);     
}