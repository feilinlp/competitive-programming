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
        int n;
        cin >> n;
        int a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);

        int ans = 1, curr = a[0];
        bool bob = true;
        for (int i=1; i<n; i++) {
            if (a[i] != a[0]) {
                if (!bob) {
                    curr = a[i];
                    ans++;
                }
                bob = !bob;
            }
        }

        cout << "ans " << ans << endl;
    }
}
