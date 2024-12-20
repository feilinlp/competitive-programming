#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        ll n;
        cin >> n;
        ll a[n+5];
        ll b[n+6];
        for (ll i=0; i<n; i++) {
            cin >> a[i];
        }
        for (ll i=0; i<=n; i++) {
            cin >> b[i];
        }
        ll last = b[n];
        ll between = -1;
        ll minimum = 1000000005;
        ll minindex = -1;
        ll sum = 0;

        for (ll i=0; i<n; i++) {
            if ((a[i]<=last && b[i] >= last) || (b[i] <= last && a[i] >= last)) {
                between = i;
            } else {
                ll x = last - a[i];
                ll y = last - b[i];
                if (x < 0)
                    x = -x;
                if (y < 0)
                    y = -y;
                if (minimum > min(x,y)){
                    minimum = min(x,y);
                    minindex = i;
                }
            }
            if (b[i] - a[i] > 0)
                sum += b[i] - a[i];
            else
                sum -= b[i] - a[i];
        }
        if (between != -1) {
            cout << sum + 1 << endl;
        } else {
            sum += minimum + 1;
            cout << sum << endl;
        }
    }
}
