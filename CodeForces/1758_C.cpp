#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n, x;
        scanf("%d %d", &n, &x);
        if (n%x!=0)
        {
            printf("-1\n");
        }
        else
        {
            for (int j=1; j<=n; j++)
            {
                if (j==1)
                    printf("%d ", x);
                else if (j==n)
                    printf("1 ");
                else if (j==x)
                {
                    for (int mul=2; mul<=n/x; mul++)
                    {
                        int rep=mul*x;
                        if(n%rep==0)
                        {
                            printf("%d ", rep);
                            x=rep;
                            break;
                        }
                    }
                }
                else
                    printf("%d ", j);
            }
            printf("\n");
        }
    }
}