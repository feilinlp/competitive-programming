#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        long long ans= (long long) n * (n+1) / 2 + (long long) n * (m+1) * m / 2 - n;
        printf("%lld\n", ans);
    }
}