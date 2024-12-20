#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m;
vector <int> segtree;

void segtreebuild()
{
    for (int i=m-1; i>=1; i--)
        segtree[i]=max(segtree[i*2],segtree[i*2+1]);
}

int segtreequery(int l, int r)
{
    int ret=0;
    for (l+=m, r+=m; l<r; l>>=1, r>>=1)
    {
        if (l&1)
            ret=max(ret, segtree[l++]);
        if (r&1)
            ret=max(ret, segtree[--r]);
    }
    return ret;
}

int main()
{
    int n;
    scanf("%d %d", &n, &m);
    segtree.resize(2*m);
    for (int i=0; i<m; i++)
    {
        scanf("%d", &segtree[m+i]);
    }
    segtreebuild();
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        bool ans=true;
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        int x=x2-x1, y=y2-y1;
        if (x<0)
            x=-x;
        if (y<0)
            y=-y;

        if (x%k!=0 || y%k!=0)
            ans=false;
        y1--;
        y2--;
        if (y1>y2)
        {
            int temp=y1;
            y1=y2;
            y2=temp;
        }
        int maxi=segtreequery(y1, y2);
        //printf("%d\n", maxi);
        
        int add=maxi/k;
        x1=x1%k;
        x1+=add*k;
        if (x1<=maxi)
            x1+=k;
        if (n-maxi<k && n<x1)
            ans=false;
        
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
}