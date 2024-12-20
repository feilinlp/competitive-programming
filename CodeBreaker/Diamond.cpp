#include <cstdio>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    for (int i=1; i<=a; i++)
    {
        for (int j=i; j<a; j++)
            printf(" ");
        for (int j=1; j<2*i; j++)
            printf("*");
        printf("\n");
    }
    for (int i=a-1; i>=1; i--)
    {
        for (int j=i; j<a; j++)
            printf(" ");
        for (int j=1; j<2*i; j++)
            printf("*");
        printf("\n");
    }
}