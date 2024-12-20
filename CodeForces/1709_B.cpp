#include <cstdio>

using namespace std;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    long long arr[m+1], ar[m+1];
    long long back[m+1];
    back[m]=0;
    ar[0]=0;
    arr[0]=0;
    for (int i=1; i<=m; i++)
    {
        scanf("%lld", &arr[i]);
        if (arr[i]<arr[i-1])
            ar[i]=ar[i-1]-arr[i]+arr[i-1];
        else
            ar[i]=ar[i-1];
    }
    for (int i=m-1; i>0; i--)
    {
        if (arr[i]<arr[i+1])
            back[i]=back[i+1]-arr[i]+arr[i+1];
        else
            back[i]=back[i+1];
    }
    for (int i=0; i<n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a<b)
            printf("%lld\n", ar[b]-ar[a]);
        else
            printf("%lld\n", back[b]-back[a]);
    }
}