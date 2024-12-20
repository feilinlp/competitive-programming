#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n;
        cin >> n;
        pair <int, int> edges[n];
        int found = 0;
        queue < pair <int, int> > process;
        process.push(make_pair(1, 2));
        bool nodes[n+1];
        for (int i=0; i<=n; i++)
            nodes[i] = false;

        while (found < n - 1) {
            if (process.empty()) {
                for (int i=1; i<=n; i++) {
                    if (!nodes[i])
                        process.push(make_pair(1, i));
                }
            }

            pair <int, int> top = process.front();
            process.pop();
            cout << "? " << top.f << " " << top.s << endl;
            cout.flush();

            // Get output
            int mid;
            cin >> mid;

            if (mid == top.f) {
                edges[found] = make_pair(top.f, top.s);
                nodes[top.f] = true;
                nodes[top.s] = true;
                found++;
            } else if (nodes[mid]) {
                process.push(make_pair(mid, top.s));
            } else {
                process.push(make_pair(top.f, mid));
                process.push(make_pair(mid, top.s));
            }
        }

        cout << "! ";
        for (int i=0; i<n-1; i++) {
            cout << edges[i].f << " " << edges[i].s << " ";
        }
        cout << endl;
    }
}
