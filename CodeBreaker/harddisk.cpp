#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int main()
{
    ll n, c;
    scanf("%lld %lld", &n, &c);
    vector < pair <ll, ll> > hd(n);
    for (ll i=0; i<n; i++)
    {
        scanf("%d %d", &hd[i].first, &hd[i].second);
    }
    sort(hd.begin(), hd.end());
    
}