#include <cstdio>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    long long t=n;
    printf("%lld ", t);
    while (t!=1)
    {
        if (t%2==1)
            t=3*t+1;
        else
            t=t/2;
        
        printf("%lld", t);
        if (t!=1)
            printf(" ");
        else
            printf("\n");
    }
}