#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        vector < pair<int, int> > q(n);
        priority_queue < pair<int, int> > qa, qb;
        for (int j=0; j<n; j++)
        {
            scanf("%d", &q[j].first);
            q[j].second=j;
            qa.push(q[j]);
        }
        qb = qa;
        vector <bool> useda(n+1, false), usedb(n+1, false);
        vector <int> a(n, 0), b(n, 0);
        bool ans=true;
        while (!qa.empty() && ans)
        {
            int val = qa.top().first;
            int ind = qa.top().second;
            qa.pop();
            if (!useda[val])
            {
                a[ind]=val;
                useda[val]=true;
            }
            else if (!usedb[val])
            {
                b[ind]=val;
                usedb[val]=true;
            }
            else
                ans=false;
        }
        int posa=n, posb=n;
        while (!qb.empty() && ans)
        {
            int pos = qb.top().second;
            qb.pop();
            if (a[pos]==0)
            {
                while (useda[posa] && posa > 0)
                {
                    posa--;
                }
                if (posa>0 && posa <= b[pos])
                {
                    a[pos]=posa;
                    useda[posa]=true;
                }
                else
                    ans=false;
            }
            else if (b[pos]==0)
            {
                while (usedb[posb] && posb > 0)
                {
                    posb--;
                }
                if (posb>0 && posb <= a[pos])
                {
                    b[pos]=posb;
                    usedb[posb]=true;
                }
                else
                    ans=false;
            }
        }
        for (int j=0; j<n; j++)
        {
            
        }
        if (ans)
        {
            printf("YES\n");
            for (int j=0; j<n; j++)
                printf("%d ", a[j]);
            printf("\n");
            for (int j=0; j<n; j++)
                printf("%d ", b[j]);
            printf("\n");
        }
        else
            printf("NO\n");
    }
}