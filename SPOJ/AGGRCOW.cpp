#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int N, C;
        scanf("%d %d", &N, &C);
        int arr[N];
        for (int i=0; i<N; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+N);
        int kiri=1, kanan=arr[N-1]-arr[0], ans=-1;
        while (kiri<=kanan)
        {
            int tengah=(kiri+kanan)/2;
            int count=1;
            int pos=0;
            int cek=1;
            while (cek<N)
            {
                if (arr[cek]-arr[pos]>=tengah)
                {
                    count++;
                    pos=cek;
                }

                if (count==C)
                    break;
                cek++;
            }
            if (count>=C)
            {
                ans=max(ans, tengah);
                kiri=tengah+1;
            }
            else
                kanan=tengah-1;
            //printf("%d\n", ans);
        }
        printf("%d\n", ans);
    }
}