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
        int x, y;
        cin >> x >> y;
        int ans = y / 2;
        x -= 7 * ans;
        if (y % 2 == 1) {
            ans += 1;
            x -= 11;
        }

        if (x > 0) {
            ans += x/15;
            if (x % 15 != 0) {
                ans += 1;
            }
        }
        
        cout << ans << endl;
    }
}
