#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int n, q, k;
    scanf("%d %d %d", &n, &q, &k);
    vector <int> p(n+1);
    for (int i=0; i<=n; i++)
        p[i]=0;
    vector < pair<int, int> > query(q);
    for (int i=0; i<q; i++)
    {
        scanf("%d %d", &query[i].first, &query[i].second);
    }
    sort(query.begin(), query.end());
    for (int i=0; i<q; i++)
    {
        priority_queue <int> pq;
        for (int j=query[i].first; j<=query[i].second; j++)
            pq.push(p[j]);
        int x=query[i].second-query[i].first+1;
        for (int j=query[i].first; j<=query[i].second; j++)
        {
            if (p[j]==0)
            {
                if (pq.top()<x)
                {
                    p[j]=x;
                }
                else if (pq.top()==x)
                {
                    pq.pop();
                    j--;
                }
                x--;
            }
        }
    }
    /*for (int i=1; i<=n; i++)
    {
        printf("%d ", p[i]);
    }*/
    vector < pair<int, int> > query2(k);
    for (int i=0; i<k; i++)
    {
        scanf("%d %d", &query2[i].first, &query2[i].second);
    }
    sort(query2.begin(), query2.end());
    int pos=0;
    bool can=true;
    for (int i=0; i<k; i++)
    {
        pos=max(pos, query2[i].first);
        for ( ; pos<query2[i].second; pos++)
        {
            if (p[pos]!=0 && p[pos+1]!=0 && p[pos]!=p[pos+1])
                can=false;
            else if (p[pos]==0)
                p[pos]=p[pos+1];
            else if (p[pos+1]==0)
                p[pos+1]=p[pos];
        }
        if (can==false)
            break;
    }
    if (can==false)
        printf("-1\n");
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (p[i]==0)
                printf("1 ");
            else
                printf("%d ", p[i]);
        }
    }
}