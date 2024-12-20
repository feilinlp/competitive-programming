#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int n, e, q;
    scanf("%d %d %d", &n, &e, &q);
    vector < vector < pair <int, int> > > path(n+1);
    for (int i=0; i<e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        path[a].push_back(make_pair(b, c));
        path[b].push_back(make_pair(a, c));
    }
    vector <int> query(q);
    int maxi=0;
    for (int i=0; i<q; i++)
    {
        scanf("%d", &query[i]);
        maxi=max(maxi, query[i]);
    }
    vector <int> answer(maxi+1, -1);
    priority_queue < pair <int, int> > pq;
}