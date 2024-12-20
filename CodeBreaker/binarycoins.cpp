#include <cstdio>

using namespace std;

int main()
{
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long count=0;
    while (n>0)
    {
        if (n%2==1)
            count++;
        n/=2;
    }
    printf("%llu\n", count);
}