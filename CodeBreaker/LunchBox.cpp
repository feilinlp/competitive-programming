#include <cstdio>
#include <algorithm>

using namespace std;

bool comp (int a, int b)
{
    return a<b;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int arr[b];
    for (int i=0; i<b; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+b, comp);
    int ans=0;
    int total=0;
    while (total<=a&&ans<b)
    {
        total+=arr[ans];
        if (total<=a)
            ans++;
        if (total>a)
            break;
    }
    printf("%d\n", ans);
}