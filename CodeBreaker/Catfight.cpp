#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    vector <long long> p(n);
    for (int i=0; i<n; i++)
    {
        scanf("%lld", &p[i]);
    }
    long long left=0, right=0, sum=0, no=0;
    while (right<=n)
    {
        if (sum<k)
        {
            no=max(no, right-left);
            sum+=p[right];
            right++;
        }
        else
        {
            sum-=p[left];
            left++;
        }
    }
    printf("%lld\n", no);
}