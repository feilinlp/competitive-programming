#include <iostream>
#define MOD 1000000007

using namespace std;

long long L, R, mod;
long long f(long long a, long long b)
{

    if (b==1)
        return a%MOD;
    else
    {
        long long z=f(a, b/2);
        z=(z%MOD * z%MOD)%MOD;
        if (b%2==1)
            z=(z*(a%MOD))%MOD;
        return z%MOD;
    }
}

long long hasil;
long long g(long long a, long long b)
{
    a=a%MOD;
    b=b%MOD;
    if (a>=b)
        hasil=(a-b)%MOD;
    else
        hasil=(a-b+MOD)%MOD;
    return hasil;
}

long long h(long long a)
{
    long long z=f(2,MOD-2)%MOD;
    long long round = (mod%MOD * g(mod, 1)%MOD)%MOD;
    long long number = (a/mod)%MOD;
    long long left = (a%mod)%MOD;
    long long count = (left%MOD *((left+1)%MOD))%MOD;
    long long final=(((((number*round)%MOD)+count)%MOD)*z)%MOD;
    //printf("%lld\n", round);
    return final;
}

int main()
{
    scanf("%lld %lld %lld", &L, &R, &mod);
    L=h(L-1);
    R=h(R);
    //printf("%lld %lld\n", L, R);
    long long hasil=g(R, L);
    printf("%lld\n", hasil);
}