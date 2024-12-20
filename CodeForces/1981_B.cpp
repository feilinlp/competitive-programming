#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    cin >> T;
    ll powers[35];
    powers[0] = 1;
    for (ll i=1; i<=31; i++) {
        powers[i] = powers[i-1] * 2;
    }
    for (ll t=0; t<T; t++) {
        ll n, m;
        cin >> n >> m;
        ll l = n - m;
        if (l < 0) {
            l = 0;
        }
        ll r = n + m;
        ll largest = 0;
        while (r > 1) {
            r /= 2;
            largest++;
        }
        // cout << "largest" << largest << endl;
        r = n + m;
        ll ans = 0;
        for (ll i=largest; i>=0; i--) {
            if (r - l >= powers[i])
                ans += powers[i];
            else if (r % powers[i+1] >= powers[i] || l % powers[i+1] >= powers[i])
                ans += powers[i];
            // cout << ans << endl;
        }
        if (m != 0)
            cout << ans << endl;
        else
            cout << n << endl;
    }
}
