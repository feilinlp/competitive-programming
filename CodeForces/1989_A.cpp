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
        if (y >= -1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
