#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define f first
#define s second

using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll a[n], c[n], x[m];
    for (ll i=0; i<n; i++)
        scanf("%lld", &a[i]);
    for (ll i=0; i<n; i++)
        scanf("%lld", &c[i]);
    for (ll i=0; i<m; i++)
        scanf("%lld", &x[i]);

    ll dp[n+1][n+1]; //the i-th item has already j items before, incl himself
    for (ll i=0; i<=n; i++)
    {
        for (ll j=0; j<=n; j++)
        {
            dp[i][j]=0;
        }
    }

    ll pos=0, start=0;
    for (ll i=1; i<=n; i++)
    {
        ll minim=1e18;
        for (ll j=1; j<i; j++) //i-1
        {
            minim=min(minim, c[i-j]);
            if (j<=pos)
                dp[i][j]=dp[i-1][j];
            else if (i!=x[pos])
                dp[i][j]=min(dp[i-1][j], dp[i-1][j-1] + a[i-1] + minim);
            else
                dp[i][j]=dp[i-1][j-1]+a[i-1]+minim;
        }
        minim=min(minim, c[0]);
        for (ll j=i; j<=n; j++)
        {
            dp[i][j]=dp[i-1][j-1]+a[i-1]+minim;
        }
        if (i==x[pos])
        {
            ll p=1e18;
            pos++;
            ll s=0;
            for (ll j=pos; j<=n; j++)
            {
                if (dp[i][j] < p)
                {
                    p=dp[i][j];
                    s=max(s, j);
                }
            }
            start=max(s, start+1);
        }
    }
    // printf("%lld\n", start);

    // for (ll i=0; i<=n; i++)
    // {
    //     for (ll j=0; j<=n; j++)
    //     {
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    ll ans=1e18;
    for (ll i=start; i<=n; i++)
    {
        // printf("??");
        ans=min(ans, dp[x[m-1]][i]);
    }
    printf("%lld\n", ans);
}