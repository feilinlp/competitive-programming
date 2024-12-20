#include <cstdio>
#include <algorithm>

using namespace std;

bool comp(int a, int b)
{
    return a>b;
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    int arr[n];
    for (int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int ans=0;
    sort(arr, arr+n, comp);
    for (int i=0; i<d; i++)
        ans+=arr[i];
    printf("%d\n", ans);
}