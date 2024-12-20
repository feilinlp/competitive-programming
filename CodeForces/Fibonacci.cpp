#include <cstdio>
#define MOD 1000000007

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    long long m[2][2], p[2][2], in[2];
    m[0][0]=0;
    m[0][1]=1;
    m[1][0]=1;
    m[1][1]=1;
    in[0]=0;
    in[1]=1;
    if (n<2)
        printf("%lld\n", n);
    else
    {
        while (n>0)
        {
            if (n%2==1)
            {
                int temp=in[0];
                in[0]=(in[0]*m[0][0]+in[1]*m[1][0])%MOD;
                in[1]=(temp*m[0][1]+in[1]*m[1][1])%MOD;
            }
            p[0][0]=0;
            p[0][1]=0;
            p[1][0]=0;
            p[1][1]=0;
            for (int i=0; i<2; i++)
            {
                for (int j=0; j<2; j++)
                {
                    for (int k=0; k<2; k++)
                    {
                        p[i][k]=(p[i][k]+m[i][j]*m[j][k])%MOD;
                    }
                }
            }
            for (int i=0; i<2; i++)
            {
                for (int j=0; j<2; j++)
                {
                    m[i][j]=p[i][j];
                }
            }
            n=n/2;
        }
        printf("%lld\n", in[0]);
    }
}