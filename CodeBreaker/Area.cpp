#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long ans=0;
    int a, b;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        ans+=(long long)a*b;
    }
    printf("%lld\n", ans);
}