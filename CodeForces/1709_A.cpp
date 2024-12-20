#include <cstdio>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);
        int d[4];
        for (int i=1; i<4; i++)
            scanf("%d", &d[i]);
        int opened=1;
        while (true)
        {
            if (d[n]==0)
                break;
            else
            {
                n=d[n];
                opened++;
            }
        }
        if (opened==3)
            printf("YES\n");
        else
            printf("NO\n");
    }
}