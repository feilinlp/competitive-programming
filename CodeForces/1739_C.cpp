#include <cstdio>
#define MOD 998244353

using namespace std;

int main()
{
    long long a[31], b[31];
    a[0] = 0;
    b[0] = 0;
    a[1] = 1;
    b[1] = 0;
    for (long long i=2; i<31; i++)
    {
        a[i] = ((2*i-1)*(a[i-1] + b[i-1] + 1) / (i)) + b[i-1];
        b[i] = ((i-1)*(a[i-1] + b[i-1] + 1) / (i)) + a[i-1];
        //printf("%lld %lld\n", a[i], b[i]);
    }

    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%lld %lld 1\n", a[x/2]%MOD, b[x/2]%MOD);
    }
}