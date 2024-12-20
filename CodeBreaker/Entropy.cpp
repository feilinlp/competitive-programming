#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int arr[a];
    for (int i=0; i<a; i++)
        scanf("%d", &arr[i]);
    b=a-b-1;
    if (b>0)
    {
        int minim=1e9;
        for (int i=0; i<=a-b; i++)
            minim=min(minim, arr[i+b]-arr[i]);
        printf("%d\n", minim);
    }
    else
        printf("0\n");
}