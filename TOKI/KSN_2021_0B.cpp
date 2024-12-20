#include <cstdio>

using namespace std;

int main()
{
    int q;
    long long k;
    scanf("%d %lld", &q, &k);
    
    long long power[35];
    power[0]=1;
    for (int i=1; i<35; i++)
    {
        power[i]=power[i-1]*2;
    }

    int bk[35];
    for (int i=0; i<35; i++)
    {
        bk[i]=k%2;
        k=k/2;
        //printf("%d", bk[i]);
    }

    long long c[q];
    int bc[35];
    int bans[35];
    bool pos=true;
    long long ans;
    for (int i=0; i<q; i++)
    {
        pos=true;
        ans=0;
        scanf("%lld", &c[i]);
        for (int j=0; j<35; j++)
        {
            //printf("%d ", j);
            bc[j]=c[i]%2;
            c[i]=c[i]/2;
            //printf("%d ", c[i]);
            if (bc[j]==0)
            {
                if (bk[j]==0)
                    bans[j]=0;
                else
                {
                    pos=false;
                    break;
                }
                //printf("bc = 0\n");
            }
            else
            {
                if (bk[j]==1)
                    bans[j]=0;
                else
                    bans[j]=1;

                //printf("bc = 1\n");
            }
        }
        if (pos==false)
            printf("-1\n");
        else
        {
            for (int j=0; j<35; j++)
                ans+=(long long) bans[j]*power[j];
            printf("%lld\n", ans);
        }
    }
}