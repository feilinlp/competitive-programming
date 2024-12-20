#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=1; t<=T; t++)
    {
        printf("Case #%d:\n", t);
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        vector < pair<long long, int> > pergi[A], pulang[A];
        for (int i=0; i<B; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            pergi[a].push_back(make_pair(c, b));
            pulang[b].push_back(make_pair(c, a));
        }
        long long arr[A];
        memset(arr, -1, sizeof(arr));
        priority_queue < pair<long long, int> > antri;
        antri.push(make_pair(0, 0));
        while (antri.empty()==false)
        {
            long long step=-antri.top().first;
            int asal=antri.top().second;
            antri.pop();

            if (arr[asal]==-1)
            {
                arr[asal]=step;
                //printf("%d %d]\n", asal, step);
                int z=pergi[asal].size();
                for (int i=0; i<z; i++)
                {
                    if (arr[pergi[asal][i].second]==-1)
                    {
                        antri.push(make_pair(-(step+pergi[asal][i].first), pergi[asal][i].second));
                    }
                }
            }
        }
        long long ar[A];
        memset(ar, -1, sizeof(ar));
        antri.push(make_pair(0, A-1));
        while (antri.empty()==false)
        {
            long long step=-antri.top().first;
            int asal=antri.top().second;
            antri.pop();

            if (ar[asal]==-1)
            {
                ar[asal]=step;
                //printf("[%d %d\n", asal, step);
                int m=pulang[asal].size();
                for (int i=0; i<m; i++)
                {
                    if (ar[pulang[asal][i].second]==-1)
                    {
                        antri.push(make_pair(-(step+pulang[asal][i].first), pulang[asal][i].second));
                    }
                }
            }
        }

        for (int i=0; i<C; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            long long total = arr[x]+z+ar[y];
            //printf("%d\n", total);
            if ((total<arr[A-1])&&(arr[x]!=-1)&&(ar[y]!=-1))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}