#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
vector < pair <int, int> > segtree;

// void segtreeprint()
// {
//     for (int i=1; i<2*n; i++)
//         printf("%d %d\n", segtree[i].first, segtree[i].second);
//     printf("segtree \n");
// }

void segtreebuild()
{
	for (int i=n-1; i > 0; i=i-1)
    {
		segtree[i].first = max(segtree[2*i].first, segtree[2*i + 1].first);
        if (segtree[2*i+1].first==segtree[2*i].first)
            segtree[i].second=min(segtree[2*i].second, segtree[2*i+1].second);
        else if (segtree[2*i].first > segtree[2*i+1].first)
            segtree[i].second=segtree[2*i].second;
        else
            segtree[i].second=segtree[2*i+1].second;
    }
}

void segtreeupdate(int x, int y)
{
    // printf("update %d %d\n", x, y);
	segtree[n+x].first = y;
	for (x = x+n>>1; x; x>>=1)
    {
		segtree[x].first = max(segtree[2*x].first, segtree[2*x + 1].first);
        if (segtree[2*x+1].first==segtree[2*x].first)
            segtree[x].second=min(segtree[2*x].second, segtree[2*x+1].second);
        else if (segtree[2*x].first > segtree[2*x+1].first)
            segtree[x].second=segtree[2*x].second;
        else
            segtree[x].second=segtree[2*x+1].second;
    }
    // segtreeprint();
}

pair <int, int> segtreequery(int l, int r)
{
	pair <int, int> ret = make_pair(-1, n);
	for (l+=n, r+=n; l<r; l>>=1, r>>=1)
	{
		if (l&1)
        {
            if (ret.first==segtree[l].first)
                ret.second=min(ret.second, segtree[l].second);
            else if (segtree[l].first > ret.first)
                ret.second=segtree[l].second;
            ret.first = max(segtree[l++].first, ret.first);
        }
		if (r&1)
        {
            if (ret.first==segtree[--r].first)
                ret.second=min(ret.second, segtree[r].second);
            else if (segtree[r].first > ret.first)
                ret.second=segtree[r].second;
            ret.first = max(segtree[r].first, ret.first);
        }
	}
	return ret;
}


int main()
{
    int m;
    scanf("%d %d", &n, &m);
    segtree.resize(2*n, make_pair(-1, n));
    for (int i=0; i<n; i++)
    {
        scanf("%d", &segtree[n+i].first);
        segtree[n+i].second=i;
    }
    segtreebuild();
    for (int i=0; i<m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        pair <int, int> x=segtreequery(a, b+1);
        printf("%d\n", x.first);
        // int y=lower_bound(segtree.begin()+n+a, segtree.begin()+n+b, x)-segtree.begin()-n;
        // printf("y %d\n", y);
        segtreeupdate(x.second, -1);
    }
}