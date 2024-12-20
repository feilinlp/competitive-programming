#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    priority_queue <int> q;
    long long ans=0;
    long long minus=0;
    int sum=0;
    int x;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        if (sum>=k)
        {
            minus+=q.top();
            q.pop();
            sum--;
        }

        if (x>=0)
        {
            minus+=x;
        }
        else
        {
            q.push(x);
            sum++;
        }

        if (minus>=0)
        {
            ans+=minus;
            minus=0;
        }
    }
    printf("%lld\n", ans);
}