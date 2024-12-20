#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector < vector <int> > edge, edges;
vector <int> to_reset;
int before[300005], visited[300005], diameter[300005];
int N;

int temp=-1, dist=-1;
void search(int s) //diameter search
{
    for (int i=0; i<edge[s].size(); i++)
    {
        if (visited[edge[s][i]]==-1)
        {
            before[edge[s][i]]=s;
            visited[edge[s][i]]=visited[s]+1;
            // to_reset.push_back(edge[s][i]);
            search(edge[s][i]);
        }
    }
    if (visited[s]>dist)
    {
        dist=visited[s];
        temp=s;
    }
}


void fw(int s) //search for longest path after diameter is removed
{
    for (int i=0; i<edges[s].size(); i++)
    {
        if (visited[edges[s][i]]==-1 && !diameter[edges[s][i]])
        {
            visited[edges[s][i]]=visited[s]+1;
            to_reset.push_back(edges[s][i]);
            fw(edges[s][i]);
        }
        // cout << __LINE__ << endl;
    }
    if (visited[s]>dist)
    {
        dist=visited[s];
        temp=s;
        // cout << __LINE__ << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N;
    edge.resize(N);
    edges.resize(N);
    int tempin[N], in[N], f[N];
    for (int i=1; i<N; i++) //cin edges
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    visited[0]=0;
    memset(visited, -1, sizeof(visited));
    memset(before, -1, sizeof(before));
    memset(diameter, 0, sizeof(diameter));
    before[0]=0;
    search(0); //search for end
    int start=temp;
    dist=-1;

    memset(visited, -1, sizeof(visited));
    memset(before, -1, sizeof(before));
    visited[start]=0;
    before[start]=start;
    search(start); //search for diameter
    int en = temp; //dist is the length
    int x=en;
    int count=0; //number of nodes in diameter
    while (before[x]!=x) //find the nodes in diameter in reversed order
    {
        tempin[count]=x;
        count++;
        x=before[x];
    }
    tempin[count]=start;
    count++;

    for (int i=0; i<count; i++) //reverse the order of nodes
    {
        in[i]=tempin[count-1-i];
        diameter[in[i]]=1;
    }

    for (int i=0; i<N; i++) //delete the nodes in diameter
    {
        for (int j=0; j<edge[i].size(); j++)
            edges[i].push_back(edge[i][j]);
    }
    // for (int i=0; i<count; i++)
    //     cout << in[i] << " ";
    // cout << endl;

    int ans=-1;
    memset(f, 0, sizeof(f)); //f stores the longest path
    memset(visited, -1, sizeof(visited));
    for (int i=1; i<count-1; i++) //find the longest path at each node of diameter
    {
        while (!to_reset.empty())
        {
            visited[to_reset.back()]=-1;
            to_reset.pop_back();
        }
        visited[in[i]]=0;
        to_reset.push_back(in[i]);
        temp=-1; dist=-1;
        fw(in[i]); //find the longest path
        f[i]=dist;
        // cout << __LINE__ << endl;
        int next=temp;
        if (next!=in[i])
        {
            while (!to_reset.empty())
            {
                visited[to_reset.back()]=-1;
                to_reset.pop_back();
            }
            // cout << __LINE__ << endl;
            visited[next]=0;
            to_reset.push_back(next);
            temp=-1; dist=-1;
            // cout << next << endl;
            fw(next); //find diameter in each node
            // cout << __LINE__ << endl;
        }
        ans=max(ans, dist);
        // cout << ans << endl;
    }
    if (N==count)
        ans=N-1;
    else
        ans+=count;
    // cout << ans << endl;

    // for (int i=0; i<count; i++)
    //     cout << f[i] << " ";
    // cout << endl;

    int a[count], b[count];
    int curr=0;
    for (int i=0; i<count; i++)
    {
        if (f[i]+i > f[curr]+curr)
            curr=i;
        a[i]=curr + f[curr];
    }
    // for (int i=0; i<count; i++)
    //     cout << a[i] << " ";
    // cout << endl;

    curr=count-1;
    for (int i=count-1; i>=0; i--)
    {
        if (f[i] + curr - i > f[curr])
            curr=i;
        b[i]= f[curr] + count-1 - curr;
    }
    // for (int i=0; i<count; i++)
    //     cout << b[i] << " ";
    // cout << endl;
    for (int i=1; i<count; i++)
    {
        ans=max(ans, a[i-1]+b[i]+1);
    }

    cout << ans << endl;
}