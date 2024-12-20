#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first > b.first;
}

int main()
{
    int n, c, q;
    scanf("%d %d %d", &n, &c, &q);
    vector <int> seats(n), processed(n, -1), latest(c, -1);
    vector < pair <int, int> > query(q);
    for (int i=0; i<n; i++)
    {
        scanf("%d", seats[i]);
    }
    for (int i=0; i<q; i++)
    {
        scanf("%d %d", &query[i].first, &query[i].second);
    }
    sort(query.begin(), query.end(), comp);

    int process=0;
    while (process<q)
    {
        if ()
    }
}