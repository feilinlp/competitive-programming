#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector <int> v(n+1), ans(n+2, 0);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &v[i]);
    }

    deque <int> dq;
    dq.push_back(0);
    for (int i=1; i<=n+1; i++)
    {
        if (i<=n)
            ans[i]=max(v[i], ans[dq.front()]);
        else
            ans[i]=ans[dq.front()];
        
        if (dq.front()==i-k)
        {
            // printf("a\n");
            dq.pop_front();
        }
        while (!dq.empty() && ans[dq.back()]>=ans[i])
        {
            // printf("b\n");
            dq.pop_back();
        }
        dq.push_back(i);
        // printf("%d %d %d\n", dq.front(), dq.back(), ans[i]);
    }
    printf("%d\n", ans[n+1]);
}