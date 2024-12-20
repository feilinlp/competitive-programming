#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct ans
{
    int length, curr, pqlength;
    priority_queue <int> filth;

    bool operator< (ans a, ans b)
    {
        if (a.length!=b.length)
            return a.length < b.length;
        else
            return a.pqlength < b.pqlength;
    }
} a;

int main()
{
    int n, e, k;
    scanf("%d %d %d", &n, &e, &k);
    vector <bool> visited(n, false);
    vector < vector < pair <int, int> > > path(n+1);
    for (int i=0; i<e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        path[a].push_back(make_pair(b, c));
        path[b].push_back(make_pair(a, c));
    }
    priority_queue <ans> pq;
    a.length=0;
    a.curr=1;
    a.pqlength=0;
    pq.push(a);
    bool a=true;
    int answer=1e9;
    while (!pq.empty())
    {
        ans temp=pq.top();
        pq.pop();
        if (temp.curr != n)
        {
            visited[temp.curr]=true;
            for (int i=0; i<path[temp.curr].size(); i++)
            {
                if (!visited[path[temp.curr][i].first])
                {
                    ans t;
                    t.length=temp.length++;
                    t.curr=path[temp.curr][i].first;
                    t.filth = temp.filth;
                    t.filth.push(-path[temp.curr][i].second);
                    t.pqlength=temp.pqlength;
                    if (temp.pqlength==k)
                    {
                        t.filth.pop();
                    }
                    else
                        t.pqlength++;
                    pq.push(t);
                }
            }
        }
        else
        {
            if (temp.pqlength<k)
            {
                a=false;
                break;
            }
            else
                answer=min(answer, -temp.filth.top());
        }
    }

    if (a)
        printf("%d\n", answer);
    else
        printf("-1\n");
}