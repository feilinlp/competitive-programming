#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int batas, T;
    scanf("%d %d", &batas, &T);
    int memo[batas];
    for (int i=0; i<batas; i++)
    {
        scanf("%d", &memo[i]);
    }
    sort(memo, memo+batas);
    for (int t=0; t<T; t++)
    {
        int cari;
        scanf("%d", &cari);
        int kiri=0, kanan=batas-1;
        int jwb=-1;
        while (kanan>=kiri)
        {
            int tengah = (kanan+kiri)/2;
            if (memo[tengah]==cari)
            {
                jwb=tengah;
                //printf("X%dX", jwb);
                kanan=tengah-1;
            }
            else if (memo[tengah]<cari)
                kiri=tengah+1;
            else
                kanan=tengah-1;
        }
        printf("%d\n", jwb);
    }
}