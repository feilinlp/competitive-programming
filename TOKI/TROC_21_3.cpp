#include <cstdio>
#define MOD 1000000007

using namespace std;

int exp(int m, int n)
{
    if (n==1)
        return m;
    else
    {
        int x = exp(m, n/2);
        x=((long long)x*x) % MOD;

        if (n%2!=0)
            x=((long long)x*m) % MOD;
        return x;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    n-=1;
    int ans=exp(m, n);
    ans=((long long)ans * (m-1))%MOD;
    ans=((long long)ans + m)%MOD;
    printf("%d\n", ans);
}