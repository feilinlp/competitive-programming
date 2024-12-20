#include <iostream>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N], minimum=1000000000, maximum=0;
    for (int i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
        minimum=min(minimum, arr[i]);
        maximum=max(maximum, arr[i]);
    }

    int jwb=1000000000;
    while (maximum>=minimum)
    {
        int tengah = (maximum+minimum)/2;
        long long total=0;
        for (int i=0; i<N; i++)
        {
            if (arr[i]>tengah)
                total=total + arr[i]-tengah;
        }
        if (total<M)
        {
            maximum=tengah-1;
        }
        else if (total==M)
        {
            jwb=tengah;
            break;
        }
        else
        {
            jwb=tengah;
            minimum=tengah+1;
        }
    }
    printf("%d\n", jwb);
}