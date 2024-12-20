#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int check(int x, int y) {
    while (x % y == 0) {
        x /= y;
    }
    return x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int x, y, k;
        cin >> x >> y >> k;
        k--;
        x++;
        // cout << x << " " << y << " " << k << endl;
        x = check(x, y);
        while (x > 1 && k > 0) {
            if (k >= y - (x%y)) {
                k -= y - (x%y);
                x += y - (x%y);
                // cout << x << " " << y << " " << k << endl;
            } else {
                x += k;
                k -= k;
            }
            x = check(x, y);
            // cout << x << " " << y << " " << k << endl;
        }

        if (x == 1 && k > 0) {
            k = k % (y-1);
            x += k;
            k -= k;
            x = check(x,y);
        }
        cout << x << endl;
    }
}
