#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> segtree(2097152, 0);
int power[21];
long long n;

void segtreebuild()
{
    for (int i=n-1; i>=1; i--)
        segtree[i]=segtree[i*2] + segtree[i*2+1];
}

void segtreeupdate(long long x, long long y)
{
    x+=1048576;
    if (segtree[x]>0 || y==1)
        segtree[x]+=y;
    for (x=x>>1; x; x>>=1)
        segtree[x]=min(segtree[2*x],segtree[2*x+1]);
    /*printf("%lld ", segtree[524288]);
    for (int i=1048576; i<1048576+6; i++)
        printf("%lld ", segtree[i]);*/
}

long long segtreequery()
{
    long long in=1;
    int layer=0;
    while (in < 1048576)
    {
        //printf("in %lld %lld\n", in, segtree[in]);
        if (segtree[in]>0)
        {
            in=in*2+1;
            if (in!=power[layer]-1)
                in++;
        }
        else
            in=in*2;
        layer++;
    }
    //printf("in %lld %lld\n", in, segtree[in]);
    if (segtree[in]>0)
        return in-1048576+1;
    else
        return in-1048576;
}

int main()
{
    scanf("%lld", &n);
    power[0]=1;
    for (int i=1; i<21; i++)
        power[i]=power[i-1]*2;
    for (long long i=0; i<n; i++)
    {
        long long b, c;
        scanf("%lld %lld", &b, &c);
        if (c<=1e6)
        {
            if (b==1)
            {
                segtreeupdate(c-1, 1);
            }
            else
            {
                segtreeupdate(c-1, -1);
            }
        }
        long long x=segtreequery();
        if (x==-1)
            printf("0\n");
        else
            printf("%lld\n", x);
    }
}