#include <bits/stdc++.h>

using namespace std;
using ll = long long;

set < pair <int, int> > diag[400010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n, d;
        cin >> n >> d;
        int x[n], y[n];
        for (int i=0; i<n; i++) {
            cin >> x[i] >> y[i];
            x[i] += 100000;
            y[i] += 100000;
        }
        
        bool poss = false;
        for (int i=0; i<n; i++) {
            diag[x[i]+y[i]].insert({x[i], i});
        }
        for (int i=0; i<n; i++) {
            auto a = diag[x[i]+y[i]].lower_bound({x[i]+d/2, -1});
            if (a == diag[x[i]+y[i]].end() || a->first != x[i]+d/2) continue;
            if (x[i]+y[i]+d < 400010) {
                auto b = diag[x[i]+y[i]+d].lower_bound({x[i]+d/2, -1});
                if (b != diag[x[i]+y[i]+d].end() && b->first <= a->first + d/2) {
                    poss = true;
                    cout << i+1 << " " << a->second + 1 << " " << b->second + 1 << endl;
                    break;
                }
            }
            if (x[i]+y[i]-d >= 0) {
                auto b = diag[x[i]+y[i]-d].lower_bound({x[i]-d/2, -1});
                if (b != diag[x[i]+y[i]-d].end() && b->first <= a->first - d/2) {
                    poss = true;
                    cout << i+1 << " " << a->second + 1 << " " << b->second + 1 << endl;
                    break;
                }
            }
        }

        for (int i=0; i<n; i++) {
            diag[x[i]+y[i]].erase({x[i], i});
        }

        if (!poss) {
            for (int i=0; i<n; i++) {
                y[i] -= 200000;
                diag[x[i]-y[i]].insert({x[i], i});
            }
            for (int i=0; i<n; i++) {
                auto a = diag[x[i]-y[i]].lower_bound({x[i]+d/2, -1});
                if (a == diag[x[i]-y[i]].end() || a->first != x[i]+d/2) continue;
                if (x[i]-y[i]+d < 400010) {
                    auto b = diag[x[i]-y[i]+d].lower_bound({x[i]+d/2, -1});
                    if (b != diag[x[i]-y[i]+d].end() && b->first <= a->first + d/2) {
                        poss = true;
                        cout << i+1 << " " << a->second + 1 << " " << b->second + 1 << endl;
                        break;
                    }
                }
                if (x[i]-y[i]-d >= 0) {
                    auto b = diag[x[i]-y[i]-d].lower_bound({x[i]-d/2, -1});
                    if (b != diag[x[i]-y[i]-d].end() && b->first <= a->first - d/2) {
                        poss = true;
                        cout << i+1 << " " << a->second + 1 << " " << b->second + 1 << endl;
                        break;
                    }
                }
            }

            for (int i=0; i<n; i++) {
                diag[x[i]-y[i]].erase({x[i], i});
            }
        }

        if (!poss)
            cout << "0 0 0\n";
    }
}
