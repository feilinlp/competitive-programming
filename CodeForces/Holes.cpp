#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector <int> num(n);
    int b=sqrt(n);
    vector <int> count(n, 0);
    vector <int> next(n, 0);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
        if ((i+1)%b==0)
        {
            //printf("%d\n", __LINE__);
            int mul=i/b+1;
            for (int j=i; j>i-b; j--)
            {
                //printf("%d\n", __LINE__);
                if (j+num[j]>=mul*b || j+num[j]>=n)
                {
                    count[j]=1;
                    //printf("%d\n", __LINE__);
                    next[j]=j+num[j];
                }
                else
                {
                    count[j]=count[j+num[j]]+1;
                    //printf("%d\n", __LINE__);
                    next[j]=next[j+num[j]];
                }
            }
            //printf("%d\n", __LINE__);
        }
    }
    /*for (int i=0; i<n; i++)
    {
        printf("%d %d\n", count[i], next[i]);
    }*/

    for (int i=0; i<m; i++)
    {
        int x;
        scanf("%d", &x);
        if (x==0)
        {
            //printf("%d\n", __LINE__);
            int a, c;
            scanf("%d %d", &a, &c);
            //printf("%d\n", __LINE__);
            a--;
            num[a]=c;
            if (a+num[a]>=(a/b+1)*b || a+num[a]>=n)
            {
                //printf("%d\n", __LINE__);
                count[a]=1;
                next[a]=a+num[a];
            }
            else
            {
                count[a]=count[a+num[a]]+1;
                next[a]=next[a+num[a]];
                //printf("%d\n", __LINE__);
            }
        }
        else
        {
            int a;
            scanf("%d", &a);
            a--;
            int ans=0, pos=a;
            //printf("%d\n", __LINE__);
            while (next[pos]<n && next[next[pos]]<n)
            {
                ans+=count[pos];
                printf(" xx ans, pos %d %d\n", ans, pos);
                //printf("%d\n", __LINE__);
                pos=next[pos];
            }
            printf("ans, pos %d %d\n", ans, pos);
            while (pos+num[pos]<n)
            {
                ans++;
                pos+=num[pos];
                printf("ans, pos %d %d\n", ans, pos);
            }
            ans+=count[pos];
            printf("%d %d\n", pos+1, ans);
        }
    }
}