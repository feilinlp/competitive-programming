#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int N;
        scanf("%d", &N);
        int jarak[N][N];
        for (int i=0; i<N; i++)
        {
            for (int j=0; j<N; j++)
            {
                scanf("%d", &jarak[i][j]);
            }
        }
        int ans=0;
        int R;
        scanf("%d", &R);
        for (int r=0; r<R; r++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            priority_queue <pair <int, int> > antri;
            bool visit[N];
            memset(visit, false, sizeof(visit));
            antri.push(make_pair(0, a-1));
            while (antri.top().second!=b-1)
            {
                int tempuh = -antri.top().first;
                int asal = antri.top().second;
                antri.pop();
                visit[asal]=true;

                for (int i=0; i<N; i++)
                {
                    int tujuan=i;
                    int mau=tempuh+jarak[asal][tujuan];
                    if (visit[tujuan]==false)
                        antri.push(make_pair(-mau, tujuan));
                }
            }
            ans=ans-antri.top().first;
        }
        printf("Case #%d: %d\n", t+1, ans);
    }
}