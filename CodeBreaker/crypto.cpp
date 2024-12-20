#include <cstdio>
#include <algorithm>
#include <vector>
#define MOD 1000000007

using ll = long long;
using namespace std;

ll n;
vector <ll> fenwick, arr;
vector < pair <ll, ll> > ar;
ll factorial[300005];

ll sum(ll m) //calculate how many numbers are smaller than itself
{
	ll ret = 0;
	for (ll i  = m; i >= 0; i-=i+1&~i)
	{
		ret += fenwick[i];
	}
	return ret-1;
}

void update(ll a, ll b)
{
	for (ll i=a; i<n; i+=i+1&~i)
	{
		fenwick[i] += b;
	}
}


int main()
{
    scanf("%lld", &n);
    ar.resize(n);
    arr.resize(n);
    fenwick.resize(n);
    // printf("%d\n", __LINE__);
    for (ll i=0; i<n; i++)
    {
        fenwick[i]=0;
        // printf("%d\n", __LINE__);
        scanf("%lld", &ar[i].first);
        // printf("%d\n", __LINE__);
        ar[i].second = i;
    }
    sort(ar.begin(), ar.end());
    for (ll i=0; i<n; i++)
    {
        update(i, 1);
        arr[ar[i].second]=i;
    }

    // printf("Fenwick ");
    // for (int i=0; i<n; i++)
    //     printf("%lld ", fenwick[i]);
    // printf("\n");

    // for (int i=0; i<n; i++)
    // {
    //     printf("%lld ", arr[i]);
    // }

    factorial[0]=1;
    for (ll i=1; i<3e5+5; i++)
        factorial[i] = factorial[i-1]*i % MOD;

    // if (arr[0] > arr[1])
    //     printf("%lld\n", factorial[n]);
    // else
    //     printf("1\n");

    ll ans=1;
    for (ll i=0; i<n; i++)
    {
        // printf("f %lld ", factorial[i]);
        // printf("sum %lld\n", sum(arr[i]));
        ans += factorial[n-1-i] * sum(arr[i]) % MOD; 
        ans %=MOD;
        update(arr[i], -1);
        // printf("Fenwick ");
        // for (int i=0; i<n; i++)
        //     printf("%lld ", fenwick[i]);
        // printf("\n");
        // printf("%lld\n", ans);
    }
    printf("%lld\n", ans%MOD);
}