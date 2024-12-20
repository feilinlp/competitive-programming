#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int arr[10005];
    for (int i=0; i<10005; i++)
        arr[i]=0;
    arr[0]=a;
    int pos=1;
    while (pos<b)
    {
        if (arr[pos-1]==1 || pos==b)
            break;
        
        if (arr[pos-1]%2==1)
            arr[pos]=3*arr[pos-1]+1;
        else
            arr[pos]=arr[pos-1]/2;
        
        pos++;
    }
    if (arr[b-1]!=0)
        printf("%d\n", arr[b-1]);
    else
        printf("-1\n");
}