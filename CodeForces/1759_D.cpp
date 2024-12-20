#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    long long t;
    scanf("%lld", &t);
    for (long long i=0; i<t; i++)
    {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long x2=0, x5=0;
        long long a=x;
        while (a%2==0 && a>0)
        {
            a /= 2;
            x2+=1;
        }
        a=x;
        while (a%5==0 && a>0)
        {
            a /= 5;
            x5+=1;
        }
        long long diff = x2-x5;
        if (x2 > x5)
        {
            long long mul = pow(5, diff);
            while (mul > y)
                mul /= 5;
            while (y/mul/10 > 0)
                mul *= 10;
            if (y/mul > 0)
                mul = y/mul * mul;
            printf("%lld\n", x * mul);
        }
        else if (x2 < x5)
        {
            diff = -diff;
            long long mul = pow(2, diff);
            while (mul > y)
                mul /= 2;
            while (y/mul/10 > 0)
                mul *= 10;
            if (y/mul > 0)
                mul = y/mul * mul;
            printf("%lld\n",  x * mul);
        }
        else
        {
            long long mul=0;
            long long b = y;
            while (b /10 > 0)
            {
                b /= 10;
                mul++;
            }
            mul = pow(10, mul);
            if (y/mul > 0)
                mul = y/mul * mul;
            if (mul == 1)
                printf("%lld\n", x * y);
            else
                printf("%lld\n", x * mul);
        }
    }
}