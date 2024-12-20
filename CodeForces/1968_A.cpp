#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        int x;
        cin >> x;
        int y = 0;
        int sum = 0;
        for (int gcd = x-1; gcd > 0; gcd--) {
            if (x % gcd == 0 && sum <= x) {
                // cout << "gcd " << gcd << endl;
                sum = x;
                y = gcd * (x / gcd - 1);
            }
        }
        cout << y << endl;
    }
}
