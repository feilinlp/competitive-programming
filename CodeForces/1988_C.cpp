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
        ll power = 0;
        ll s = n;
        while (n > 0) {
            n /= 2;
            power++;
        }
        ll bit[power];
        n = s;
        ll curr = 0;
        while (n > 0) {
            bit[curr] = n % 2;
            curr++;
            n /=2;
        }

        vector <ll> ans;
        ans.push_back(s);
        ll minus = 1;
        for (ll i=0; i<power; i++) {
            if (bit[i])
                ans.push_back(s - minus);
            minus *= 2;
        }

        int x = ans.size();
        if (ans[x-1] == 0)
            x--;

        cout << x << endl;
        for (ll i=x-1; i>=0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
}
