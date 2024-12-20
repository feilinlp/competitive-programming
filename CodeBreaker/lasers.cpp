#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int maxi=0;
    int curr=0;
    for (int i=0; i<d; i++)
    {
        int x;
        scanf("%d", &x);
        curr=0;
        for (int j=0; j<x; j++)
        {
            int y;
            scanf("%d", &y);
            curr+=y;
        }
        maxi=max(maxi, curr);
    }
    int ans = maxi * 2- n;
    printf("%d\n", ans);
}