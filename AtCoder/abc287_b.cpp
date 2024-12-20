#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int s[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &s[i]);
        s[i]%=1000;
    }
    int t[m];
    for (int i=0; i<m; i++)
    {
        scanf("%d", &t[i]);
    }
    
    int ans=0;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (t[j]==s[i])
            {
                ans++;
                break;
            }
        }
    }
    printf("%d\n", ans);
}