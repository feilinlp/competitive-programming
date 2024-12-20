#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> four(2e6, 0), sev(2e6, 0), nd(2e6, 0), ni(2e6, 0), lazy(2e6, 0);
string s;

#define dr int node=0, int curl=0, int curr=n
#define lc l, curl, mid
#define rc r, mid, curr
#define lrmid int l=node+1, r=node+(curr-curl&~1), mid=(l+r)/2
#define ncc node, curl, curr

void build(dr)
{
    if (curr-curl>1)
    {
        lrmid;
        build(lc);
        build(rc);
        four[node]=four[l]+four[r];
        sev[node]=sev[l]+sev[r];
        nd[node]=max(four[l]+nd[r], nd[l]+sev[r]);
        ni[node]=max(sev[l]+ni[r], ni[l]+four[r]);
    }
    else
    {
        if (s[curl]=='4')
            four[curl]++;
        else
            sev[curl]++;
        nd[curl]++;
        ni[curl]++;
    }
}

void prop(dr)
{
    if (curr-curl>1)
    {
        lrmid;
    }
}

void rangeUpdate(int x, int y, dr)
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
    rangeUpdate(x, y, lc);
    rangeUpdate(x, y, rc);
    st[node].val=(st[l].val+st[r].val)%mod;
}

int main()
{
    int k;
    scanf("%d %d", &n, &k);
    cin>>s;
    build();
    for (int i=0; i<k; i++)
    {
        string x;
        cin>>x;
        if (x=="count")
        {
            rangeQuery();
        }
        else
        {
            int x, y;
            scanf("%d %d", &x, &y);
            y++;
            rangeUpdate(x, y);
        }
    }
}