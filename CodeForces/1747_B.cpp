#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int T=0; T<t; T++)
    {
        int n;
        scanf("%d", &n);
        if (n%2==1)
        {
            int x = (n+1)/2;
            printf("%d\n", x);
        }
        else
        {
            int x = n/2;
            printf("%d\n", x);
        }
        int a = 2, b = 3*n;
        while (a < b)
        {
            printf("%d %d\n", a, b);
            a += 3;
            b -= 3;
        }
    }
}