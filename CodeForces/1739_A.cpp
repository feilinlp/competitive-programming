#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int m, n;
        scanf("%d %d", &m, &n);
        if (m==3)
        {
            if (n==2 || n==3)
                printf("2 2\n");
            else
                printf("1 1\n");
        }
        else if (n==3 && m==2)
        {
            printf("2 2\n");
        }
        else
        {
            printf("1 1\n");
        }
        
    }
}