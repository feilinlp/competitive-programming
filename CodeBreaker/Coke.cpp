#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first*b.second > b.first*a.second;
}

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    vector <long long> c(n), s(n);
    vector < pair<long long, long long> > d(n);
    for (long long i=0; i<n; i++)
    {
        scanf("%lld", &c[i]);
    }
    for (long long i=0; i<n; i++)
    {
        scanf("%lld", &s[i]);
    }
    for (long long i=0; i<n; i++)
    {
        d[i]=make_pair(c[i], s[i]);
    }
    sort(d.begin(), d.end(), comp);
    long long ks[n+1][k+1];
    
    for (long long i=1; i<=k; i++)
    {
        for (long long j=0; j<=n; j++)
            ks[j][i]=-1;
    }
    for (long long i=0; i<=n; i++)
        ks[i][0]=0;
    long long ans=-2;
    for (long long i=1; i<=k; i++)
    {
        for (long long j=1; j<=n; j++)
        {
            if (i < d[j-1].first || ks[j-1][i-d[j-1].first]==-1)
            {
                ks[j][i]=ks[j-1][i];
            }
            else
            {
                ks[j][i]=max(ks[j-1][i], ks[j-1][i-d[j-1].first]+(i-d[j-1].first)*d[j-1].second);
            }
            ans=max(ans, ks[j][i]);
        }
    }
    // for (long long i=0; i<=k; i++)
    // {
    //     for (long long j=0; j<=n; j++)
    //     {
    //         printf("%lld ", ks[j][i]);
    //     }
    //     printf("\n");
    // }
    printf("%lld\n", ans);
}