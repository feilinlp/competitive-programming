#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector <ll> a, b;
    for (ll i=0; i<n/2; i++)
    {
        ll x;
        scanf("%lld", &x);
        a.push_back(x);
    }
    for (ll i=n/2; i<n; i++)
    {
        ll x;
        scanf("%lld", &x);
        b.push_back(x);
    }
    vector <ll> asum, bsum;
    asum.push_back(0);
    bsum.push_back(0);
    for (ll i=0; i<a.size(); i++)
    {
        ll size=asum.size();
        for (ll j=0; j<size; j++)
            asum.push_back(a[i]+asum[j]);
    }
    for (ll i=0; i<b.size(); i++)
    {
        ll size=bsum.size();
        for (ll j=0; j<size; j++)
            bsum.push_back(b[i]+bsum[j]);
    }
    sort(bsum.begin(), bsum.end());
    ll count=0;
    for (ll i=0; i<asum.size(); i++)
    {
        count+=upper_bound(bsum.begin(), bsum.end(), m-asum[i])-bsum.begin();
    }
    printf("%lld\n", count);
}