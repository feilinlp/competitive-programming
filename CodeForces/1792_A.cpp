#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int T=0; T<t; T++)
    {
        int n;
        scanf("%d", &n);
        vector <int> m(n);
        int one=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &m[i]);
            if (m[i]==1)
                one++;
        }
        int ans=one/2;
        ans += n - ans * 2;
        printf("%d\n", ans);
    }
}