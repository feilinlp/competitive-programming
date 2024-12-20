#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define MOD 998244353
#define ll long long

using namespace std;

ll n;
vector < vector <ll> > child;
ll curr[100005];
ll ans=1, node=0, edge=0;
vector < vector <int> > ab;

void dfs(ll N)
{
    // cout << __LINE__ << endl;
    // cout << N << " " << __LINE__ << endl;
    curr[N]=1;
    node++;
    
    for (ll i=0; i<child[N].size(); i++)
    {
        // cout << __LINE__ << endl;
        if (ab[N][child[N][i]]<=0)
        {
            continue;
        }
        else
        {
            ab[N][child[N][i]]--;
            ab[child[N][i]][N]--;
        }
        edge++;
        if (child[N][i]==N)
        {
            ans=ans*n % MOD;
        }
        else if (curr[child[N][i]])
        {
            ans=ans*2%MOD;
        }
        else
        {
            // cout << __LINE__ <<endl;
            dfs(child[N][i]);
            ab[N][child[N][i]]--;
            ab[child[N][i]][N]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    ll T;
    cin >> T;
    for (ll t=0; t<T; t++)
    {
        ans=1;
        cin >> n;
        child.resize(n+1);
        memset(curr, 0, sizeof(curr));
        ab.resize(n+1, (vector <int> (n+1, 0)));
        ll a[n], b[n];
        for (ll i=1; i<=n; i++)
        {
            cin >> a[i-1];
            for (ll j=1; j<=n; j++)
                ab[i][j]=0;
        }

        for (ll i=0; i<n; i++)
        {
            cin >>b[i];
        }

        for (ll i=0; i<n; i++)
        {
            if (!ab[a[i]][b[i]])
            {
                child[a[i]].push_back(b[i]);
            }
            ab[a[i]][b[i]]++;
            // cout << __LINE__ << endl;
            if (!ab[b[i]][a[i]])
            {
                child[b[i]].push_back(a[i]);
            }
            ab[b[i]][a[i]]++;
        }

        // for (int i=0; i<=n; i++)
        // {
        //     cout << child[i].size(); 
        // }
        // cout << endl;

        for (ll i=1; i<=n; i++)
        {
            if (curr[i])
                continue;
            else
            {
                dfs(i);
                // cout << __LINE__ << endl;
                // cout << __LINE__ << endl;
                // cout << i << " " << node << " "<< edge<<endl;
                if (node!=edge)
                    ans*=0;
                node=0;
                edge=0;
            }
        }
        cout << ans << endl;
        child.clear();
        ab.clear();
    }
}