#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n, c;
        scanf("%d %d", &n, &c);
        int ans=0;
        bool uses=false; //use start
        bool used[n+1]; //index start from 1
        priority_queue < pair <int, int> > start, end;
        for (int i=1; i<=n; i++)
        {
            used[i]=false;
            int x;
            scanf("%d", &x);
            start.push(make_pair(-(x + i), -i));
            // printf("huh %d\n", x+i);
            end.push(make_pair(-(x + n+1 - i), -i));
        }
        
        int left=0;
        if (c + start.top().first >= 0)
        {
            uses=true;
            used[-start.top().second]=true;
            c += start.top().first;
            left = -start.top().second;
            ans++;
            start.pop();
        }
        // printf("c %d\n", c);

        while (uses && (!start.empty() || !end.empty()))
        {
            // printf("%d\n", __LINE__);
            while (!start.empty() && used[-start.top().second])
            {
                start.pop();
                // printf("%d\n", __LINE__);
            }
            while (!end.empty() && used[-end.top().second])
            {
                end.pop();
                // printf("%d\n", __LINE__);
            }
            // printf("start end %d %d\n", start.top().first, end.top().first);
            if (!start.empty() && (end.empty() || start.top().first>=end.top().first))
            {
                int add=0;
                // printf("%d\n", __LINE__);
                if (-start.top().second < left)
                {
                    //alr there left --> left & (n+1--start.top().second), not there
                    add += 2*left - n - 1;
                }
                if (add < 0)
                    add=0;
                if (c + add + start.top().first < 0)
                {
                    start.pop();
                    continue;
                }
                c += add + start.top().first;
                if (-start.top().second < left)
                    left = -start.top().second;
                // printf("c %d\n", c);
                used[-start.top().second]=true;
                start.pop();
                ans++;
                // printf("A\n");
            }
            else if (!end.empty())
            {
                int add=0;
                if (-end.top().second < left)
                {
                    //alr there left --> left & (n+1--end.top().second), not there
                    add += 2*(left - -end.top().second);
                }
                
                // printf("%d\n", __LINE__);
                if (c + add + end.top().first < 0)
                {
                    end.pop();
                    continue;
                }
                c += add + end.top().first;
                if (-end.top().second < left)
                    left = -end.top().second;
                // printf("c %d\n", c);
                used[-end.top().second]=true;
                end.pop();
                ans++;
                // printf("B\n");
            }
        }
        printf("%d\n", ans);
    }
}