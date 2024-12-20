#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    vector < vector < pair<int, int> > > path(n+1);
    for (int i=0; i<e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        path[a].push_back(make_pair(b, c));
        path[b].push_back(make_pair(a, c));
    }
    vector <int> visited(n+1, 0);
    priority_queue < pair <int, int> > pq;
    pq.push(make_pair(0, 1));
    while (true)
    {
        int pos = pq.top().second;
        int dist = -pq.top().first;
        if (pos == n)
        {
            printf("%d\n", dist);
            break;
        }
        pq.pop();
        if (visited[pos]!=1)
        {
            visited[pos]=1;
            for (int i=0; i<path[pos].size(); i++)
            {
                if (visited[path[pos][i].first]!=1)
                {
                    pq.push(make_pair(-max(dist, path[pos][i].second), path[pos][i].first));
                }
            }
        }
    }
}