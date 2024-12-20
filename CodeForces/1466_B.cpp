#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int T=0; T<t; T++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        int list[2*n+5];
        for (int i=0; i<2*n+5; i++)
            list[i]=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            list[arr[i]]++;
        }
    
        int curr=0, ans=0;
        int one=0;
        for (int i=2*n+2; i>=0; i--)
        {
            if (list[i]!=0)
                ans++;
            if (list[i]==1 && one==0)
            {
                one=1;
            }
            else if (list[i]==0)
            {
                one=0;
            }
            else if (list[i]>1&& (one==1||one==0))
            {
                ans++;
                one=2;
            }
        }
        printf("%d\n", ans);
    }
}