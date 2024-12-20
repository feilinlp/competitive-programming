#include <cstdio>
#include <vector>

using namespace std;
#define mod 998244353
using ll = long long;

#define dr int node=0, int curl=0, int curr=n
#define lrmid int l=node+1, r=(curr-curl&~1)+node, mid=(curr+curl)/2
#define lc l, curl, mid
#define rc r, mid, curr
#define ncc node, curl, curr

struct el
{
    ll val, b=1, c=0;
};

int n;
vector <el> st;

void build(vector <ll> &in, dr)
{
    if (curr-curl>1)
    {
        lrmid;
        build(in, lc);
        build(in, rc);
        st[node].val=(st[l].val+st[r].val)%mod;
    }
    else
        st[node].val=in[curl];
}

void pro(dr)
{
    if (curr-curl>1)
    {
        lrmid;
        st[l].b=(st[node].b * st[l].b)%mod;
        st[l].c=(st[node].b * st[l].c + st[node].c)%mod;
        st[r].b=(st[node].b * st[r].b)%mod;
        st[r].c=(st[node].b * st[r].c + st[node].c)%mod;
    }
    st[node].val=(st[node].val*st[node].b+st[node].c*(curr-curl))%mod;
    st[node].b=1;
    st[node].c=0;
}

void rangeUpdate(int x, int y, ll b, dr)
{
    if (x<=curl && y>=curr)
    {
        st[node].b=(st[node].b * b)%mod;
        st[node].c=(b * st[node].c + c)%mod;
        pro(ncc);
        return;
    }

    pro(ncc);
    if (x>=curr||y<=curl)
    {
        return;
    }
    lrmid;
    rangeUpdate(x, y, b, c, lc);
    rangeUpdate(x, y, b, c, rc);
    st[node].val=(st[l].val+st[r].val)%mod;
}

ll ans;
void rangeQuery(int x, int y, dr)
{
    pro(ncc);
    if (x<=curl && y>=curr)
    {
        ans+=st[node].val;
        return;
    }

    if (x>=curr || y<=curl)
    {
        return;
    }

    lrmid;
    rangeQuery(x, y, lc);
    rangeQuery(x, y, rc);
}


int main()
{
    int q;
    scanf("%d %d", &n, &q);
    vector <ll> in(n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld", &in[i]);
    }
    st.resize(2*n);
    build(in);
    
    for (int i=0; i<q; i++)
    {
        int x;
        scanf("%d", &x);
        if (x==1)
        {
            ll l, r, m;
            scanf("%lld %lld %lld %lld", &l, &r, &m);
            rangeUpdate(l, r, m);
        }
        else
        {
            ll l, r;
            scanf("%lld %lld", &l, &r);
            ans=0;
            rangeQuery(l, r);
            printf("%lld\n", ans%mod);
        }
    }
}