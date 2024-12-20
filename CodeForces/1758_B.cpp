#include <cstdio>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    for (int i=0; i<a; i++)
    {
        int x;
        scanf("%d", &x);
        if (x%2==1)
        {
            for (int j=0; j<x; j++)
                printf("1 ");
            printf("\n");
        }
        else
        {
            for (int j=0; j<x-2; j++)
            {
                printf("2 ");
            }
            printf("1 3\n");
        }
    }
}