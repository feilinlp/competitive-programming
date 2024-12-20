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
    for (int x=0; x<T; x++) {
        ll n, m;
        cin >> n >> m;
        ll p[n+m+1];
        ll t[n+m+1];
        ll ans[n+m+1];
        ll sum=0;
        for (ll i=0; i<n+m+1; i++) {
            cin >> p[i];
        }
        for (ll i=0; i<n+m+1; i++)
            cin >> t[i];
        
        ll pcount = 0;
        ll tcount = 0;
        ll pmax = -1;
        ll tmax = -1;
        for (ll i=0; i<n+m+1; i++) {
            if (p[i] > t[i]) {
                if (pcount == n) {
                    pmax = i;
                    break;
                } else {
                    pcount += 1;
                    sum += p[i];
                }
            } else {
                if (tcount == m) {
                    tmax = i;
                    break;
                } else {
                    tcount += 1;
                    sum += t[i];
                }
            }
        }

        if (pmax != -1) {
            for (ll i=pmax; i<n+m+1; i++) {
                sum += t[i];
            }
        } 
        else {
            for (ll i=tmax; i<n+m+1; i++) {
                sum += p[i];
            }
        }

        if (pmax != -1) {
            for (ll i=0; i<pmax; i++) {
                if (p[i] > t[i]) {
                    ans[i] = sum - p[i] + p[pmax] - t[pmax];
                }
                else
                    ans[i] = sum - t[i];
            }
            for (ll i=pmax; i<n+m+1; i++) {
                ans[i] = sum - t[i];
            }
        }
        else {
            for (ll i=0; i<tmax; i++) {
                if (t[i] > p[i]) {
                    ans[i] = sum - t[i] + t[tmax] - p[tmax];
                }
                else
                    ans[i] = sum - p[i];
            }
            for (ll i=tmax; i<n+m+1; i++) {
                ans[i] = sum - p[i];
            }
        }

        for (ll i=0; i<n+m+1; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
