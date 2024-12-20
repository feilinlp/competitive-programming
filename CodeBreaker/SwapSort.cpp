#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, q;
    scanf("%d", &n);
    vector <int> p(n+1);
    int wrong=0;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &p[i]);
        if (p[i]!=i)
            wrong++;
    }
    scanf("%d", &q);
    int ans=0;
    for (int i=0; i<q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l!=p[l] && p[l]==r)
            wrong--;
        else if (l==p[l])
            wrong++;

        if (r!=p[r] && p[r]==l)
            wrong--;
        else if (r==p[r])
            wrong++;
        
        int temp=p[l];
        p[l]=p[r];
        p[r]=temp;
        if (wrong==0)
            ans++;
    }
    printf("%d\n", ans);
    for (int i=1; i<=n; i++)
        printf("%d ", p[i]);
}