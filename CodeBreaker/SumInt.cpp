#include <cstdio>

using namespace std;

int main()
{
    int d;
    scanf("%d", &d);
    long long ans=0;
    int t;
    for (int i=0; i<d; i++)
    {
        scanf("%d", &t);
        ans+=t;
    }
    printf("%lld\n", ans);
}