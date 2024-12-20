#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector < vector<long long> > t(n, vector <long long> (n, 3e18));
    for (int i=0; i<m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        t[b-1][a-1]=c;
    }
    vector <long long> in(n, 0);
    while (k>0)
    {
        if (k&1)
        {
            vector <long long> temp(n, 3e18);
            for (int i=0; i<n; i++)
            {
                for (int j=0; j<n; j++)
                {
                    temp[i]=min(temp[i], t[i][j]+in[j]);
                }
            }
            in=temp;
        }
        vector < vector<long long> > temp(n, vector <long long> (n, 3e18));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                for (int k=0; k<n; k++)
                {
                    temp[i][k]=min(temp[i][k], t[i][j]+t[j][k]);
                }
            }
        }
        t=temp;
        k=k/2;
    }
    long long ans=3e18;
    for (int i=0; i<n; i++)
    {
        ans=min(ans, in[i]);
    }
    if (ans>1e18)
        printf("IMPOSSIBLE\n");
    else 
        printf("%lld\n", ans);
}