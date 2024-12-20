#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int out=0;
    while (out<n)
    {
        if (n%m!=0)
        {
            printf("1 ");
            m--;
            n--;
        }
        else
        {
            for (int i=0; i<n; i++)
                printf("%d ", n/m);
            break;
        }
    }
}