#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        int M, N;
        scanf("%d %d", &M, &N);
        vector < pair<int, int> > memo[M+1];
        for (int i=0; i<N; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            memo[a].push_back(make_pair(c, b));
        }
        int p, q;
        scanf("%d %d", &p, &q);
        priority_queue < pair<int, int> > antri;
        antri.push(make_pair(0,p));
        int ans=-1;
        bool visit[M+1];
        bool ketemu=false;
        memset(visit, false, sizeof(visit));
        if (memo[p].size()==0)
            printf("NO\n");
        else
        {
            //printf("masuk");
            while (antri.empty()==false)
            {
                if (antri.top().second==q)
                {
                    ketemu=true;
                    break;
                }
                //printf("masuk");
                int jarak=-antri.top().first;
                int asal=antri.top().second;
                antri.pop();
                visit[asal]=true;

                int x=memo[asal].size();
                for (int i=0; i<x; i++)
                {
                    int tujuan=memo[asal][i].second;
                    int tempuh=jarak+memo[asal][i].first;
                    //printf("%d %d\n", -tempuh, tujuan);
                    if (visit[i]==false)
                    {
                        antri.push(make_pair(-tempuh, tujuan));
                    }
                }
            }

            if (ketemu==true)
            {
                ans=-antri.top().first;
                printf("%d\n", ans);
            }
            else
                printf("NO\n");
        }   
    }
}