#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int X;
        scanf("%d", &X);
        pair <int, int> arr[X];
        int hasil[X];
        for (int i=0; i<X; i++)
        {
            scanf("%d", &arr[i].first);
            hasil[i]=0;
        }
        for (int i=0; i<X; i++)
        {
            scanf("%d", &arr[i].second);
        }
        sort(arr, arr+X);
        for (int i=0; i<X; i++)
        {
            int a=0, b=0;
            while (a!=arr[i].second)
            {
                if (hasil[b]==0)
                    a++;
                b++;
            }
            while (hasil[b]!=0)
            {
                b++;
            }
            hasil[b]=arr[i].first;
        }
        for (int i=0; i<X; i++)
        {
            printf("%d", hasil[i]);
            if (i!=X-1)
                printf(" ");
            else
            printf("\n");
        }
    }
}