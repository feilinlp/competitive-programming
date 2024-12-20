#include <cstdio>
#include <utility>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

ll depth[100001];
pair <ll, ll>  parent[100001], powerparent[100001][19];
vector < pair <ll, ll> > connect[100001];

void dfs(ll x=0)
{
    powerparent[x][0].first=parent[x].first;
    powerparent[x][0].second=parent[x].second;
    for (ll i=1; i<19; i++)
    {
        powerparent[x][i].first=powerparent[powerparent[x][i-1].first][i-1].first;
        powerparent[x][i].second=powerparent[powerparent[x][i-1].first][i-1].second + powerparent[x][i-1].second;
    }
    for (ll y=0; y<connect[x].size(); y++)
    {
        if (parent[connect[x][y].first].first==-1)
        {
            parent[connect[x][y].first].first=x;
            parent[connect[x][y].first].second=connect[x][y].second;
            depth[connect[x][y].first]=depth[x]+1;
            dfs(connect[x][y].first);
        }
    }
}

ll lca(ll x, ll y)
{
    ll ret=0;
    if (depth[x]<depth[y])
    {
        ll temp=x;
        x=y;
        y=temp;
    }
    for (ll i=0; i<19; i++)
    {
        //printf("Depth = %lld %lld\n", depth[x], depth[y]);
        //printf("%lld = %lld\n", i, (depth[x]-depth[y])>>i&1);
        if ((depth[x]-depth[y])>>i&1)
        {
            //printf("x = %lld\n", x);
            ret+=powerparent[x][i].second;
            x=powerparent[x][i].first;
            //printf("x = %lld ret = %lld\n", x, ret);
        }
    }
    if (x==y)
        return ret;
    for (ll i=19; i--;) // 18 - 0
    {
        if (powerparent[x][i].first!=powerparent[y][i].first)
        {
            ret+=powerparent[x][i].second + powerparent[y][i].second;
            x=powerparent[x][i].first;
            y=powerparent[y][i].first;
            //printf("Ret = %lld\n", ret);
        }
    }
    //printf("%lld %lld\n", ret, parent[x].second);
    return ret + parent[x].second + parent[y].second;
}

int main()
{
    ll n, q;
    scanf("%lld %lld", &n, &q);
    for (ll i=0; i<100001; i++)
    {
        parent[i].first=-1;
        for (ll j=0; j<19; j++)
            powerparent[i][j].first=-1;
    }
    parent[0].first=0;
    parent[0].second=0;
    connect[0].push_back(make_pair(1, 0));
    depth[0]=0;
    for (ll i=1; i<n; i++)
    {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        connect[a].push_back(make_pair(b, c));
        connect[b].push_back(make_pair(a, c));
    }
    dfs();
    /*for (ll i=0; i<5; i++)
    {
        for (ll j=0; j<3; j++)
            //printf("%d %d\n", powerparent[i][j].first, powerparent[i][j].second);
    }*/
    for (ll i=0; i<q; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", lca(a, b));
    }
}