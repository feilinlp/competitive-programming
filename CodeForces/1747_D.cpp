#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int n;
vector <int> segtree, pxor, zero, last;
map<int, int> odd, even;

int main()
{
    int q;
    scanf("%d %d", &n, &q);
    segtree.resize(n+1, 0);
    pxor.resize(n+1, 0);
    zero.resize(n+1, 0);
    last.resize(n+1, -1);
    even[0]=0;
    int cur=0;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &segtree[i]);
        cur ^= segtree[i];
        pxor[i]=cur;
        if (segtree[i]==0)
        {
            zero[i] = zero[i-1];
        }
        else
        {
            zero[i] = i;
        }
        if(i & 1) {
    		if(even.count(cur)) {
    			last[i] = even[cur];
    		}
    		odd[cur] = i;
    	}
    	else {
    		if(odd.count(cur)) {
    			last[i] = odd[cur];
    		}
    		even[cur] = i;
    	}
    }
    // build();
    // for (int i=1; i<=n; i++)
    // {
    //     printf("%d ", zero[i]);
    // }
    // for (int i=0; i<2*pow; i++)
    // {
    //     printf("%d ", segtree[i]);
    // }
    for (int t=0; t<q; t++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        if (pxor[r] != pxor[l-1])
        {
            printf("-1\n");
        }
        else
        {
            if (zero[r] < l)
            {
                printf("0\n");
            }
            else if (r%2 == l%2)
            {
                printf("1\n");
            }
            else if (segtree[l]==0 or segtree[r]==0)
            {
                printf("1\n");
            }
            else if(last[r] >= l) {
                printf("2\n");
            }
            else {
                printf("-1\n");
            }
        }
    }
}

// 331331 --> -1 not 2