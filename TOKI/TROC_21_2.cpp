#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);
    vector <int> in(n);
    for (int i=0; i<n; i++)
    {
        scanf("%d", &in[i]);
    }
    int l=0, r=1, ans=0;
    while (r<n)
    {
        int curl=in[l];
        int curr=in[r];
        if (curr-curl<d)
        {
            r++;
        }
        else if (curr-curl==d)
        {
            ans++;
            r++;
            l++;
        }
        else
        {
            l++;
        }
        
    }
    printf("%d\n", ans);
}