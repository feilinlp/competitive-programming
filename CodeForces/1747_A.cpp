#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        long long sum=0;
        for (int j=0; j<n; j++)
        {
            long long x;
            scanf("%lld", &x);
            sum += x;
        }
        if (sum < 0)
            sum = -sum;
        printf("%lld\n", sum);
    }
}