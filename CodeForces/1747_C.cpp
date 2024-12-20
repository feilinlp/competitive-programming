#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);
        int a, b=1e9;
        scanf("%d", &a);
        for (int i=1; i<n; i++)
        {
            int x;
            scanf("%d", &x);
            b = min(b, x);
        }
        if (a > b)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
}