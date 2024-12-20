#include <cstdio>
#include <vector>
#define ll long long

using namespace std;

int main()
{
    ll n,m;
    scanf("%lld %lld", &n, &m);
    vector <ll> h(n);
    ll curr=0;
    ll tallest=0;
    ll ans=0;
    for (ll i=0; i<n; i++)
    {
        scanf("%lld", h[i]);
        if (h[i]>h[tallest]+i-tallest)
        {
            tallest=i;
            
        }
    }
}