
#include <iostream>
#define MOD 1000000007

using namespace std;

long long f(long long a)
{
    if (a==0)
        return 1;
    else if (a==1)
        return 3;
    else
    {
        long long jwb = f(a/2)%MOD;
        jwb=((jwb%MOD)*(jwb%MOD))%MOD;
        if (a%2==1)
            jwb=((jwb%MOD)*3)%MOD;
        return jwb%MOD;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        long long A;
        scanf("%lld", &A);
        long long hasil=f(((A/3)%(MOD-1))-1)%MOD;
        if (A%3==1)
            hasil=((hasil%MOD)*4)%MOD;
        else if (A%3==2)
            hasil=((hasil%MOD)*6)%MOD;
        else
            hasil=((hasil%MOD)*3)%MOD;
        
        if (A==1)
            printf("1\n");
        else if (A==2)
            printf("2\n");
        else
            printf("%lld\n", hasil%MOD);
    }
}