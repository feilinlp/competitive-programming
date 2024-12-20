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
        //printf("%d\n", n);
        int d[n];
        for (int j=0; j<n; j++)
            scanf("%d", &d[j]);
        int a[n];
        a[0] = d[0];
        bool one = true;
        for (int j=1; j<n; j++)
        {
            //printf("%d %d\n", a[j-1], d[j]);
            if (a[j-1] - d[j] >= 0 && d[j] != 0)
            {
                one = false;
                break;
            }
            else
                a[j] = a[j-1] + d[j];
        }

        if (one)
        {
            for (int j=0; j<n; j++)
                printf("%d ", a[j]);
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
}