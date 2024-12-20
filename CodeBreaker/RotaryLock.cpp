#include <iostream>
#include <vector>

using namespace std;

vector <long long> fenwick;

long long sum(long long x, long long mod)
{
    long long temp=0;
    for (long long i=x; i>=0; i-=i+1&~i)
    {
        temp+=fenwick[i]%mod;
        temp=temp%mod;
    }
    return temp%mod;
}

void update(long long x, long long y)
{
    for (long long i=x; i<fenwick.size(); i+=i+1&~i)
        fenwick[i]+=y;
}

int main()
{
    long long n, q, k;
    scanf("%lld %lld %lld", &n, &q, &k);
    long long mod=1;
    for (int i=0; i<k; i++)
    {
        mod*=2;
    }
    fenwick.resize(n+1, 0);
    long long total=0;
    for (long long i=0; i<q; i++)
    {
        long long x;
        scanf("%lld", &x);
        if (x==0)
        {
            long long a, b;
            scanf("%lld %lld", &a, &b);
            total += b%mod;
            total = total % mod;
            update(n-a+1, b%mod);
        }
        else
        {
            long long c;
            scanf("%lld", &c);
            //printf("Total : %lld %lld\n", total, sum(c));
            long long ans=(total - sum(n-c, mod))%mod;
            while (ans<0)
                ans+=mod;
            printf("%lld\n", ans) ;
        }
    }
}
