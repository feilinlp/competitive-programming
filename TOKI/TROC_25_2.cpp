#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    long long n, f, d;
    scanf("%lld %lld %lld", &n, &f, &d);
    vector <long long> time(n+1, 0);
    long long total=f*(f-1)/2;
    long long t=n-f+1;
    if (t%2==0)
    {
        t = t/2;
        total += (f+t-1)*(f+t) - (f-1)*f;
    }
    else
    {
        t = t/2;
        total += (f+t-1)*(f+t) - (f-1)*f + f + t;
    }
    if (total >= d && n>=f && d>=f)
        printf("YES\n");
    else
        printf("NO\n");
}