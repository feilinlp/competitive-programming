#include <iostream>
#include <algorithm>

using namespace std;

int main ()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int X;
        scanf("%d", &X);
        int a, b;
        pair <int, int> arr[X];
        for (int i=0; i<X; i++)
        {
            scanf("%d %d", &a, &b);
            arr[i] = make_pair(b, a);
        }
        sort(arr, arr+X);
        int i=0, c=0, count=1;
        while (i<X)
        {
            if (arr[c].first<arr[i].first)
            {
                if (arr[i].second>=arr[c].first)
                {
                    count++;
                    c=i;
                }
            }
            i++;
        }
        printf("%d\n", count);
    }
}