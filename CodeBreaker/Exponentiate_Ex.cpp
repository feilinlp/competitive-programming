#include <cstdio>

using namespace std;

long long ans[40];
long long mod=1e18;
void exp (long long a, long long b, long long m)
{   
    if (b>1)
        exp(a, b/2, m);
    long long temp=0;
    //printf("%lld\n", ans[39]);
    for (int i=39; i>=0; i--)
    {
        long long y=temp/100000000000000000;
        y=(y*mod)%m;
        temp=temp%100000000000000000;
        temp*=10;
        temp+=ans[i]+y;
        temp=temp%m;
    }
    long long x=temp;
    for (int i=0; i<40; i++)
    {
        ans[i]=x%10;
        x=x/10;
    }
    //printf("%lld\n", temp);
    for (int i=39; i>=0; i--)
    {
        ans[i]=(ans[i]*temp)%m;
    }
    for (int i=0; i<40; i++)
    {
        ans[i+1]=(ans[i+1]+ans[i]/10)%m;
        ans[i]=ans[i]%10;
    }
    temp=0;
    //printf("%lld\n", ans[39]);
    for (int i=39; i>=0; i--)
    {
        long long y=temp/100000000000000000;
        y=(y*mod)%m;
        temp=temp%100000000000000000;
        temp*=10;
        temp+=ans[i]+y;
        temp=temp%m;
    }
    x=temp;
    for (int i=0; i<40; i++)
    {
        ans[i]=x%10;
        x=x/10;
    }
    if (b&1)
    {
        for (int i=39; i>=0; i--)
        {
            ans[i]=(ans[i]*a)%m;
        }
        for (int i=0; i<40; i++)
        {
            ans[i+1]=(ans[i+1]+ans[i]/10)%m;
            ans[i]=ans[i]%10;
        }
    }
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        long long a, b, m;
        scanf("%lld %lld %lld", &a, &b, &m);
        a=a%m;
        ans[0]=1;
        for (int i=1; i<40; i++)
            ans[i]=0;
        mod=1000000000000000000%m;
        exp(a, b, m);
        long long temp=0;
        for (int i=39; i>=0; i--)
        {
            temp*=10;
            temp+=ans[i];
            //printf("%lld", ans[i]);
        }
        printf("%lld\n", temp);
    }
}