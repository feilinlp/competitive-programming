#include <iostream>

using namespace std;

int main()
{
    long long A, B, hasil=0, memo=1;
    scanf("%lld %lld", &A, &B);
    while ((A!=0)&&(B!=0))
    {
        hasil=0;
        memo=1;
        A=A%100000007;
        for (long long i=1; i<=B; i++)
        {
            memo=(memo*A)%1000000007;
            hasil=(hasil+memo)%1000000007;
        }
        printf("%lld\n", hasil);
        scanf("%lld %lld", &A, &B);
    }
}