#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> segtree;
long long n;

void segtreebuild()
{
    for (int i=n-1; i>=1; i--)
        segtree[i]=segtree[i*2] + segtree[i*2+1];
}

void segtreeupdate(long long x, long long y)
{
    segtree[x+n]=y;
    for (x=x+n>>1; x; x>>=1)
        segtree[x]=min(segtree[2*x],segtree[2*x+1]);
    /*for (int i=1; i<10; i++)
        printf("%lld", segtree[i]);*/
}

long long segtreequery(long long l, long long r)
{
    long long ret=1e9;
    for (l+=n, r+=n; l<r; l>>=1, r>>=1)
    {
        if (l&1)
            ret=min(ret, segtree[l++]);
        if (r&1)
            ret=min(ret, segtree[--r]);
    }
    return ret;
}

int main()
{
    long long q;
    scanf("%lld %lld", &n, &q);
    segtree.resize(n*2, 0);
    for (long long i=0; i<q; i++)
    {
        long long b, c, d;
        scanf("%lld %lld %lld", &b, &c, &d);
        if (b==1)
        {
            segtreeupdate(c, d);
        }
        else
        {
            printf("%lld\n", segtreequery(c, d+1));
        }
    }
}