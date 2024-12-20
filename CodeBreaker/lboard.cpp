#include <cstdio>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector < vector <ll> > numbers(n), left(n), right(n), up(m), down(m);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            ll x;
            scanf("%lld", &x);
            numbers[i].push_back(x);
        }
    }
    long long curr=0, minim=0;
    for (int i=0; i<n; i++)
    {
        curr=0;
        minim=0;
        for (int j=0; j<m; j++)
        {
            minim=min(minim, curr);
            left[i].push_back(curr-minim);
            curr+=numbers[i][j];
        }
    }
    for (int i=0; i<n; i++)
    {
        curr=0;
        minim=0;
        for (int j=m-1; j>=0; j--)
        {
            minim=min(minim, curr);
            right[i].push_back(curr-minim);
            curr+=numbers[i][j];
        }
    }
    for (int i=0; i<m; i++)
    {
        curr=0;
        minim=0;
        for (int j=0; j<n; j++)
        {
            minim=min(minim, curr);
            up[i].push_back(curr-minim);
            curr+=numbers[j][i];
        }
    }
    for (int i=0; i<m; i++)
    {
        curr=0;
        minim=0;
        for (int j=n-1; j>=0; j--)
        {
            minim=min(minim, curr);
            down[i].push_back(curr-minim);
            curr+=numbers[j][i];
        }
    }

    // for (int i=0; i<n; i++)
    // {
    //     for (int j=0; j<m; j++)
    //     {
    //         printf("%lld ", down[j][n-1-i]);
    //     }
    //     printf("\n");
    // }

    long long ans=-1e9;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            ll hor=max(left[i][j], right[i][m-1-j]);
            ll ver=max(up[j][i], down[j][n-1-i]);
            ans=max(ans, hor+ver+numbers[i][j]);
            // printf("%lld %lld %lld\n", hor, ver, ans);
        }
    }
    printf("%lld\n", ans);
}