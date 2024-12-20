#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll T;
    cin >> T;
    for (ll t=0; t<T; t++) {
        ll n;
        cin >> n;
        ll h[n+1];
        for (ll i=0; i<n; i++)
            cin >> h[i];
        h[n] = 0;
        
        ll ans = h[n], curr = n;
        for (ll i=n-1; i>=0; i--) {
            if (h[i] >= ans + 1) {
                ans = h[i];
            } else {
                ans++;
            }
        }

        cout << ans << endl;
    }
}
