#include <cstdio>
#include <vector>
#include <algorithm>
#define s second
#define f first

using ll = long long;
using namespace std;

ll n, d;
vector <ll> segtree;
ll power=1;
vector < pair <ll, pair <ll, ll> > > arr, ar; 
//arr -> minimum starting fuel, distance, refill
//ar -> distance, minimum starting fuel, refill

void segtreeupdate(ll x, ll y)
{
	segtree[x+power] += y;

	for (x = x+power>>1; x; x>>=1)
    {
        // printf("Hello\n");
        if (segtree[2*x+1]>=0 || (segtree[2*x]<=0 && segtree[2*x+1]<=0))
        {
            segtree[x] = segtree[2*x] + segtree[2*x+1];
        }
        else if (segtree[2*x]>=0 && segtree[2*x+1]<=0)
        {
            segtree[x] = segtree[2*x];
        }

        if (x & (x-1)!=0)
        {
            if (segtree[2*x-2]>=0 && segtree[2*x-1]<0)
            {
                segtree[x] += segtree[2*x-1];
            }
        }
    }

    // printf("segtree ");
    // for (int i=1; i<power*2; i++)
    //     printf("%lld ", segtree[i]);
    // printf("\n");
}

int main()
{
    scanf("%lld %lld", &n, &d);
    while (power < n+1)
    {
        power *= 2;
    }
    segtree.resize(power*2, 0);
    arr.resize(n+1);
    ar.resize(n+1);
    ll prev=0;

    for (ll i=0; i<n; i++)
    {
        scanf("%lld %lld %lld", &arr[i].s.f, &arr[i].s.s, &arr[i].f);
        ar[i].f = arr[i].s.f;
        ar[i].s.f = arr[i].f;
        ar[i].s.s = arr[i].s.s;
    }
    arr[n].f=0; arr[n].s.f = d; arr[n].s.s=0;
    ar[n].f=d; ar[n].s.f=0; ar[n].s.s=0;

    sort(arr.begin(), arr.end());
    sort(ar.begin(), ar.end());

    for (ll i=0; i<=n; i++)
    {
        // printf("arr %lld %lld %lld\n", arr[i].f, arr[i].s.f, arr[i].s.s);
        // printf("ar %lld %lld %lld \n", ar[i].f, ar[i].s.f, ar[i].s.s);
        // printf("%lld ", ar[i].f - prev);
        segtreeupdate(i, ar[i].f - prev);
        // printf("%lld\n", segtree[1]);
        prev=ar[i].f + ar[i].s.s;
        // printf("%lld\n", prev);
    }
    // printf("%lld\n", segtree[1]);

    ll pos=0;
    while (segtree[1]>arr[pos].f && pos <= n)
    {
        while (arr[pos+1].f==arr[pos].f)
        {
            segtreeupdate(pos, arr[pos].s.s);
            pos++;
        }
        segtreeupdate(pos, arr[pos].s.s);
        pos++;
    }
    if (pos > n)
        printf("%lld\n", d);
    else
        printf("%lld\n", segtree[1]);
}