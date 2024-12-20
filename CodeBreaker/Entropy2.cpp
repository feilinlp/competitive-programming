#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#define ll long long

using namespace std;

int main()
{
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll sum=0;
    ll change=0;
    vector < pair<ll, ll> > c;
    c.push_back(make_pair(0, 0));
    for (int i=0; i<n; i++)
    {
        ll x;
        scanf("%lld", &x);
        if (x<0)
        {
            change++;
            c.push_back(make_pair(-x, -1));
        }
        else
        {
            change--;
            c.push_back(make_pair(x, 1));
        }
        sum+=x;
    }
    sort(c.begin(), c.end());
    ll pos=0, no=c.size();
    ll curr=sum;
    while (pos<no-1 && c[pos+1].first<k)
    {
        change+=c[pos].second;
        curr+=change*(c[pos+1].first-c[pos].first);
        sum=max(sum, curr);
        pos++;
    }
    change+=c[pos].second;
    curr+=change*(k-c[pos].first);
    sum=max(sum, curr);
    printf("%lld\n", sum);
}