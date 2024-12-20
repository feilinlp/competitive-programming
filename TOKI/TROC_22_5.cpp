#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
using ll = long long;

vector <int> L;
ll curl, curr;
void binser(int l, int r, int val)
{
    int mid=(l+r)/2;
    printf("%lld %lld %d %d %d\n", curl, curr, l, r, mid);
    while (curl==0)
    {
        if (L[mid-1]==-1)
        {
            printf("? %d", mid-1);
            scanf("%d", &L[mid-1]);
        }

        if (L[mid]==-1)
        {
            printf("? %d", mid);
            scanf("%d", &L[mid]);
        }

        if (L[mid-1]!=val)
            curl=mid;
        else
            binser(l, mid-1, val);
    }

    while (curr==0)
    {
        if (L[mid+1]==-1)
        {
            printf("? %d", mid+1);
            scanf("%d", &L[mid+1]);
        }
        if (L[mid]==-1)
        {
            printf("? %d", mid);
            scanf("%d", &L[mid]);
        }
        if (L[mid+1]!=val)
            curr=mid;
        else
            binser(mid+1, r, val);
    }
}

int main()
{
    ll N;
    scanf("%lld", &N);
    L.resize(N+1);
    for (int i=0; i<N+1; i++)
        L[i]=-1;
    int x=-1, y=-1;
    ll a=-1, b=-1;
    ll query=1;
    ll diff=0;
    
    while (x==-1)
    {
        printf("%lld %lld\n", diff, query);
        query+=diff;
        diff++;
        printf("? %lld\n", query);
        scanf("%d", &L[query]);
        if (diff!=1 && L[query]==L[query-diff+1])
        {
            ll l = query-diff+1, r=query, mid=(l+r)/2;
            curl=0;
            curr=0;
            if (mid==1)
                curl=1;
            if (mid==N)
                curr=N;
            if (L[l]!=L[mid])
            {
                int val=L[mid];
                binser(l, r, val);
            }
            x=curr-curl+1;
        }
    }

    if (L[1]==0)
    {
        curr=0;
        binser(1, x, 0);
        a=x-curr;
    }
    else
    {
        curr=0;
        binser(1, x, 1);
        a=2*x-curr;
    }

    if (L[N]==0)
    {
        curl=0;
        binser(N-x+1, N, 0);
        b=2*x-N+curl-1;
    }
    else
    {
        curl=0;
        binser(N-x+1, N, 1);
        b=x-N+curl-1;
    }

    y=(N+a+b)/2;
    y=y/x;
    printf("! %d %d %lld %lld\n", x, y, a, b);
}