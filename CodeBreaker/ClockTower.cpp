#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long h, mul;
    scanf("%d %lld", &n, &h);
    vector <long long> p(n);
    mul=h/n;
    int ans=0;
    for (int i=1; i<n; i++)
    {
        //printf("%d\n", __LINE__);
        scanf("%lld", &p[i]);
        if (p[i]>=(long long)mul*i)
            ans++;
        //printf("%d\n", __LINE__);
    }
    if (ans==0)
        printf("Yes\n");
    else
        printf("No\n%d", ans);
}