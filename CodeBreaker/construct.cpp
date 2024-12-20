#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#define MOD 1000000007

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    ll n, m, k;
    cin >> n >> m >> k;
    ll dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));
    vector < pair <ll, ll> > path;

    for (ll i=0; i<k; i++)
    {
        ll a,b;
        cin >> a >> b;
        path.push_back(make_pair(a, b));
    }

    for (ll i=1; i<=n; i++)
        dp[1][i]=1;
    
    for (ll i=2; i<=m; i++)
    {
        ll prev=0;
        for (ll j=1; j<=n; j++)
            prev=(prev+dp[i-1][j]) % MOD;
        for (ll j=1; j<=n; j++)
        {
            dp[i][j]=prev % MOD;
        }

        for (ll j=0; j<path.size(); j++)
        {
            ll from=path[j].first, to=path[j].second;
            dp[i][to] = (dp[i][to] - dp[i-1][from]) % MOD;
            if (dp[i][to] < 0)
                dp[i][to]+=MOD;
        }
    }

    ll ans=0;
    for (ll i=1; i<=n; i++)
        ans = (ans + dp[m][i]) % MOD;
    cout << ans << endl;
}
