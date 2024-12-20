#include <cstdio>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    bool ans=true;
    while (n>0)
    {
        if (n%5==2 || n%5==3)
        {
            ans=false;
            //printf("1\n");
            break;
        }
        else if (n%5==4)
            n=(n+1)/5;
        else
            n=n/5;
    }
    if (ans==true)
        printf("YES\n");
    else
        printf("NO\n");
}