#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int N;
int sorted[300001];

void update(int a, int b)
{
    for (int i=a; i<N; i+=i+1&-i-1)
    {
        sorted[i] += b;
        //printf("%d %d ", i, sorted[i]);
    }
}

int get(int a)
{
    int ret=0;
    for (int i=a; i>=0; i-=i+1&-i-1)
    {
        ret+=sorted[i];
    }
    return ret;
}

int main() 
{
    scanf("%d", &N);
    int faktorial[N];
    faktorial[0]=1;
    for (int i=1; i<N; i++)
    {
        faktorial[i]=(long long) faktorial[i-1]*i%mod;
        //printf("%d ", faktorial[i]);
    }
    
	int array[N];
    for (int i=0; i<N; i++)
    {
        scanf("%d", &array[i]);
        sorted[i]=array[i];
    }
    sort(sorted, sorted + N);

    for (int i=0; i<N; i++)
    {
        int kiri=0, kanan=N-1;
        while (kiri<=kanan)
        {
            int tengah = (kiri + kanan)/2;
            if (array[i]>sorted[tengah])
            {
                kiri=tengah+1;
            }
            else if (array[i]==sorted[tengah])
            {
                array[i]=tengah;
                kanan = kiri-1;
                break;
            }
            else
            {
                kanan=tengah-1;
            }
        }
    }

    for (int i=0; i<N; i++)
    {
        sorted[i]=0;
    }
    
    for (int i=1; i<N; i++)
    {
        update(i, 1);
    }

    int hasil=1;
    for (int i=0; i<N; i++)
    {
        //printf("%d ", array[i]);
        int m=get(array[i]);
        update(array[i]+1, -1);
        hasil=(hasil+(long long)faktorial[N-i-1]* (long long) m) % mod;
    }
    printf("%d\n", hasil);
}