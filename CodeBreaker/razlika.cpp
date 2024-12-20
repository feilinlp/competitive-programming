#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> v(n);
    for (int i=0; i<n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    vector <int> diff(n-1); // 0 is diff for 0 and 1
    for (int i=0; i<n-1; i++)
    {
        diff[i]=v[i+1]-v[i];
    }
    int total=v[n-1]-v[0];
    // printf("%d\n", total);
    int ans=-1e9; //reduction from removing - min --> as large
    int left=0, right=0;
    for (int i=0; i<k; i++)
        left+=diff[i];
    int minim=n-2;
    for (int i=n-3; i>=k; i--)
    {
        if (diff[minim] >= diff[i])
            minim=i;
    }
    for (int i=0; i<=k; i++)
    {
		// printf("%d %d %d %d\n", total, left, right, diff[minim]);
        int curr=left+right-diff[minim];
        ans=max(ans, curr);
        left -= diff[k-1-i];
        right += diff[n-2-i];
        if (diff[minim] >= diff[k-1-i])
        {
            minim=k-1-i;
        }
        else if (minim==n-2-i)
        {
            minim=n-3-i;
            for (int j=k-1-i; j<n-3-i; j++)
            {
                if (diff[j] < diff[minim])
                    minim=j;
            }
        }
        // printf("%d\n", ans);
    }
    printf("%d\n", total - ans);
}