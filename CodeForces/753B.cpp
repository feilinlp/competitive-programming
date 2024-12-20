#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (b%4==0)
        {
            printf("%lld\n", a);
        }
        else if (b%4==1)
        {
            if (a%2==0)
                printf("%lld\n", a-b);
            else
                printf("%lld\n", a+b);
        }
        else if (b%4==2)
        {
            if (a%2==0)
                printf("%lld\n", a+1);
            else
                printf("%lld\n", a-1);
        }
        else
        {
            if (a%2==0)
                printf("%lld\n", a+b+1);
            else
                printf("%lld\n", a-b-1);
        }
    }
}