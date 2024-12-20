#include <cstdio>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector <pair<int, int>> route[n+1];
    for (int i=0; i<m; i++)
    {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        route[x].push_back(make_pair(y, d));
        route[y].push_back(make_pair(x, d));
    }
    int k;
    scanf("%d", &k);
    int maxsch=0;
    vector <int> stu;
    for (int i=0; i<k; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        priority_queue <pair<int, int>> pq;
        pq.push(make_pair(0, a));
        while (!pq.empty())
        {
            
        }
    }
    
}