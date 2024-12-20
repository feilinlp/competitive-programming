#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    vector <int> k(n);
    int ans=0, sum=0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &k[i]);
        if (i<x)
            sum+=k[i];
        else
        {
            ans=max(ans, sum);
            //printf("%d %d\n", i-x, sum);
            sum+=k[i]-k[i-x];
        }
    }
    ans=max(ans, sum);
    printf("%d\n", ans);
}