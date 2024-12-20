#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using ll = long long;

vector <ll> a, depth;
vector < vector <int> > edge;

pair < pair <ll, ll> , ll> dfs (int p, int d)
{
    depth[p] = d;
    // cout << "pd " << p << ' ' << d << endl;

    vector <pair < pair <ll, ll> , ll> > pairs;
    for (int i = 0; i < edge[p].size(); i++)
    {
        // cout << p << " " << edge[p][i] << " " << depth[edge[p][i]] << endl;
        if (depth[edge[p][i]] == -1)
            pairs.push_back(dfs(edge[p][i], d+1));
    }

    pair < pair <ll, ll> , ll> ret;
    if (d%2) {
        ret.f.f = 0;
        ret.f.s = a[p];
        ret.s = 0;
        for (int i=0; i<pairs.size(); i++) {
            ret.f.f += pairs[i].s;
            if (pairs[i].f.f > pairs[i].f.s) {
                ret.f.f += pairs[i].f.f;
                ret.f.s += pairs[i].f.s;
            } else {
                ret.f.f += pairs[i].f.s;
                ret.s += pairs[i].f.f;
            }
        }
    } else {
        ret.f.s = 0;
        ret.f.f = a[p];
        ret.s = 0;
        for (int i=0; i<pairs.size(); i++) {
            ret.f.s += pairs[i].s;
            if (pairs[i].f.s < pairs[i].f.f) {
                ret.f.s += pairs[i].f.s;
                ret.f.f += pairs[i].f.f;
            } else {
                ret.f.s += pairs[i].f.f;
                ret.s += pairs[i].f.s;
            }
        }
    }

    cout << a[p] << " " << ret.f.f << " " << ret.f.s << " " << ret.s << endl;
    return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        edge.clear();
        depth.clear();
        a.clear();

        int n;
        cin >> n;
        a.resize(n);
        edge.resize(n);
        depth.resize(n, -1);
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=1; i<n; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        // cout << "edge" << endl;
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<edge[i].size(); j++) {
        //         cout << i+1 << " " << edge[i][j]+1 << endl;
        //     }
        // }
        pair < pair <ll, ll> , ll > ans = dfs(0, 0);
        cout << 2*(ans.f.f + ans.f.s + ans.s) - max(max(ans.f.f, ans.f.s), ans.s) + min(min(ans.f.f, ans.f.s), ans.s) << endl;
    }
}
