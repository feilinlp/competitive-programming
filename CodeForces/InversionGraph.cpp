#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int n;
        scanf("%d", &n);
        vector <int> s(n);
        for (int i=0; i<n; i++)
        {
            scanf("%d", &s[i]);
        }
        queue <int> q;
        int curr=s[0];
        for (int i=1; i<n; i++)
        {
            if (s[i]>curr)
            {
                q.push(curr);
                curr=s[i];
            }
            else
            {
                while (!q.empty() && s[i]<q.front())
                {
                    q.pop();
                }
            }
        }
        q.push(curr);
        printf("%d\n", q.size());
    }
}