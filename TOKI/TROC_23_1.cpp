#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int factor=1;
    int m = sqrt(n);
    if (n!=m*m)
    {
        printf("NO\n");
    }
    else
    {
        for (int i=2; i<m; i++)
        {
            if (n%i==0)
                factor++;
        }
        if (factor!=2)
            printf("NO\n");
        else
            printf("YES\n");
    }
}