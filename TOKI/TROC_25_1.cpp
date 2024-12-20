#include <cstdio>

using namespace std;

long long exp(long long b)
{
    if (b==1)
        return 2;
    else if (b%2==0)
    {
        long long ans = exp(b/2);
        return ans*ans;
    }
    else
    {
        long long ans = exp(b-1);
        return ans*2;
    }
}

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a>b)
        printf("%lld\n", b * exp(a-b));
    else
        printf("%lld\n", a);
}