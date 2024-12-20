#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=1; i<=t; i++)
    {
        for (int j=0; j<i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}