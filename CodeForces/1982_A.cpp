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
        int a,b;
        cin >> a >> b;
        int c,d;
        cin >> c >> d;
        if (a < b) {
            if (d <= c) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
        else {
            if (c <= d) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
}
