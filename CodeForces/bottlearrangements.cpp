#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int r=0, w=0;
        for (int i=0; i<m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            r = max(r, a);
            w = max(w, b);
        }
        if (r+w > n)
        {
            printf("IMPOSSIBLE\n");
        }
        else
        {
            for (int i=0; i<r; i++)
                printf("R");
            for (int i=0; i<w; i++)
                printf("W");
            for (int i=0; i<n-r-w; i++)
                printf("W");
            printf("\n");
        }
    }
}