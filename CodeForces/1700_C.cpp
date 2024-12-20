#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, left=-1, right;
vector <int> tree;
long long ans;

long long calc (int x, int y)
{
	//printf("xy %d %d\n", x, y);
	//printf("tree %d %d\n", tree[0], tree[1]);
	if (x>=n || y<0)
		return 0;
    if (y==x+1)
    {
    	//printf("lr %d %d\n", left, right);
        if (x<left || x>right)
        {
            //printf("%d\n", __LINE__);
            //printf("1 %lld\n", tree[x]);
            return tree[x];
        }
        else
        {
            //printf("%d\n", __LINE__);
            //printf("2 %lld\n", ans);
            return tree[x]*3;
        }
    } 
    if (y<=x)
        return 0;
    int minim=2e9, index=-1;
    for (int i=x; i<y; i++)
    {
        //printf("%d\n", __LINE__);
        if (minim>tree[i])
        {
            minim=tree[i];
            index=i;
        }
    }
    for (int i=x; i<y; i++)
        tree[i]-=minim;
    //printf("%d\n", __LINE__);
    //printf("3 %lld %d\n", ans, index);
    return calc(x, index) + calc(index+1, y) + minim; 
} 

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        //printf("%d\n", __LINE__);
        scanf("%d", &n);
        ans=0;
        tree.resize(n);
        int minim=2e9, index=-1;
        //printf("%d\n", __LINE__);
        left=-1;
        right = n;
        for (int j=0; j<n; j++)
        {
            tree[j]=0;
            int x;
            //printf("%d\n", __LINE__);
            scanf("%d", &x);
            tree[j]=x;
            if (minim>tree[j])
            {
                index=j;
                //printf("ind %d\n", index);
                minim=tree[j];
                //printf("min %d\n", minim);
            }
            //printf("%d\n", __LINE__);
        }
        int curr=0;
        while (left==-1)
        {
            if(tree[curr+1]>tree[curr])
            {
                left = curr;
                break;
            }
            //printf("curr %d\n", curr);
            //printf("%d\n", __LINE__);
            curr++;
            if (curr==n-1)
            	left=n;
        }
        curr=n-1;
        while (right==n)
        {
            if (tree[curr-1]>tree[curr])
            {
                right = curr;
                break;
            }
            //printf("%d\n", __LINE__);
            curr--;
            if (curr==1)
            	right=-1;
        }
        if (minim<0)
        	ans-=minim;
        else
        	ans+=minim;
        //printf("4 %lld\n", ans);
        for (int j=0; j<n; j++)
        {
            tree[j]-=minim;
            //printf("%d\n", __LINE__);
        }
        ans += calc(0, index) + calc(index+1, n);
        //printf("%d\n", __LINE__);
        printf("%lld\n", ans);
    }
}