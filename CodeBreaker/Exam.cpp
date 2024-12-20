#include <cstdio>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    if (a==1)
    {
        printf("Hello World\n");
    }
    else
    {
        int x, y;
        scanf("%d %d", &x, &y);
        long long z=(long long)x*y;
        printf("%lld\n", z);
    }
}