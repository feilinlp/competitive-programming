#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    int x=sqrt(n);
    bool prime=true;
    if (n!=0&&n!=1)
    {
        for (int i=2; i<=x; i++)
        {
            if (n%i==0)
            {
                prime=false;
                break;
            }
        }
    }
    else
        prime=false;
    if (prime==false)
        printf("Not ");
    printf("Prime\n");
}