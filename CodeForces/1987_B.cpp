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
        ll a[n];
        for (ll i=0; i<n; i++)
            cin >> a[i];
        
        ll diff[n-1];
        ll maxi = a[0];
        for (ll i=1; i<n; i++) {
            maxi = max(maxi, a[i-1]);
            diff[i-1] = maxi - a[i];
        }

        sort(diff, diff+n-1);

        // for (ll i=0; i<n-1; i++)
        //     cout << diff[i] << " ";

        ll count = 1, start = 0, prev = 0;
        ll ans = 0;
        
        while (diff[start] <= 0) {
            start++;
        }

        for (ll i=start+1; i<n-1; i++) {
            if (diff[i] != diff[i-1]) {
                ans += (n - start) * (diff[i-1] - prev);
                count = 1;
                prev = diff[i-1];
                start = i;
            }
        }

        if (start < n - 1)
            ans += (n - start) * (diff[n-2] - prev);

        cout << ans << endl;
    }
}
