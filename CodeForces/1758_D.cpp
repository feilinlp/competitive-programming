#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        if (n%2==0)
        {
            for (int i=n/2; i>0; i--)
            {
                printf("%d ", n+i);
            }
            for (int i=1; i<=n/2; i++)
            {
                printf("%d ", n-i);
            }
        }
        else
        {
            int x=n/2 - 1, y=n+2;
            int start=y+x;
            printf("%d ", start+2);
            printf("%d ", start+1);
            start--;
            for (int j=2; j<n-1; j++)
            {
                printf("%d ", start);
                start--;
            }
            printf("%d ", start-1);
        }
        printf("\n");
    }
}