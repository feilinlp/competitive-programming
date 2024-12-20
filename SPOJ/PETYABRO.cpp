#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int arr[N+1];
    priority_queue < pair< pair<int, int>, int> > antri;
    int visited=0;
    for (int i=1; i<=N; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i]==1)
        {
            visited++;
            antri.push(make_pair(make_pair(0,0), i));
        }
    }
    
    int a,b,c;
    vector < pair<int, int> > memo[N+1];
    for (int i=1; i<=M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        memo[a].push_back(make_pair(c, b));
        memo[b].push_back(make_pair(c, a));
    }
    
    long long total=0;
    while (antri.empty()==false)
    {
        if (visited==N)
        {
            break;
        }

        int x=-antri.top().first.first;
        int y=-antri.top().first.second;
        int z=antri.top().second;
        antri.pop();

        if (arr[z]!=1)
        {
            total=total+y;
            arr[z]=1;
            visited++;
        }

        int j=memo[z].size();
        for (int i=0; i<j; i++)
        {
            if (arr[memo[z][i].second]!=1)
                antri.push(make_pair(make_pair(-x-memo[z][i].first, -memo[z][i].first), memo[z][i].second));
        }
    }

    if (visited==N)
        printf("%lld\n", total);
    else
        printf("impossible\n");
}