#include <cstdio>
#include <vector>

using namespace std;

vector <int> searched, depth;

vector < vector <int> > child, starting;

void clear()
{
    depth.clear();
    searched.clear();
    child.clear();
    starting.clear();
}

void dfs(int x)
{
    for (int i=0; i<child[x].size(); i++)
    {
        searched.push_back(child[x][i]);
        //printf("%d\n", searched[searched.size()-1]);
        //printf("%d\n", child[x][i]);
        dfs(child[x][i]);
    }
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t=0; t<T; t++)
    {
        clear();
        int n, k;
        scanf("%d %d", &n, &k);
        child.resize(n);
        depth[0]=0;
        for (int i=1; i<n; i++)
        {
            int p;
            scanf("%d", &p);
            p-=1;
            depth[i] = depth[p] + 1;
            child[p].push_back(i);
        }
        searched.push_back(0);
        dfs(0);

        starting.push_back(searched[1]);
        for (int i=2; i<n; i++)
        {
            if (de)
        }
        /*for (int i=0; i<n; i++)
        {
            printf("%d\n", searched[i]);
        }*/
        // dfs will remain the same, binary search in between segments, largest index difference (store starting indexes in vector in vector), priority queue
    }
}