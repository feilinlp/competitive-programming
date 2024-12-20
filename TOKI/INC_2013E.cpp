#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        int X, count=0, maximum=0;
        scanf("%d", &X);
        int arr[X], prefix[X];
        for (int i=0; i<X; i++)
        {
            scanf("%d", &arr[i]);
            if (i>0)
                prefix[i]=arr[i]^prefix[i-1];
            else
                prefix[i]=arr[i];
        }
        sort(prefix, prefix+X);
        int i=0, banyak=1;
        while (i<X-1)
        {
            if (prefix[i]==0)
                count++;
            if (prefix[i+1]==prefix[i])
                banyak++;
            else
            {
                count=count+banyak*(banyak-1)/2;
                //printf("%d %d\n", prefix[i], banyak);
                banyak=1;
            }
            i++;
        }
        if (prefix[X-1]==0)
            count++;
        count=count+banyak*(banyak-1)/2;
        printf("Case #%d: %d\n", t, count);
    }
}