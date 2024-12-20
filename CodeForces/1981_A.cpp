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
        int l, r;
        cin >> l >> r;
        int ans = 0;
        while (r >= 2) {
            r /= 2;
            ans++;
        }
        cout << ans << endl;
    }
}
