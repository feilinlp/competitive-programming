#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    int arr[5000001];
    memset(arr, 0, sizeof(arr));
    //printf("%d\n", arr[1]);
    for (int i=1; i<3162; i++)
    {
        int min=(i*(i+1))/2;
        //printf("%d\n", min);
        while (min<=5000000)
        {
            arr[min]++;
            min=min+i;
            //printf("%d\n", arr[1]);
            //printf("%d ", min);
        }
    }
    for (int t=1; t<=T; t++)
    {
        int A, B, C, D;
        int count=0;
        scanf("%d %d %d %d", &A, &B, &C, &D);
        for (int i=A; i<=B; i++)
        {
            if ((C<=arr[i])&&(arr[i]<=D))
                count++;
        }
        printf("Case #%d: %d\n", t, count);
    }
}