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
        int a, b;
        cin >> a >> b;
        int diff = a - b;
        if (diff < 0)
            diff = -diff;
        
        int ans = 1;
        while (diff % 2 == 0) {
            ans *= 2;
            diff /= 2;
        }

        cout << ans << endl;
    }
}
