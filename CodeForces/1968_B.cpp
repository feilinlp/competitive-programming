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
        int m, n;
        cin >> m >> n;
        char a[m], b[n];
        cin >> a >> b;
        int curr = 0;
        for (int j=0; j<n; j++) {
            if (curr == m) break;
            if (b[j] == a[curr]) {
                curr += 1;
            }
        }
        cout << curr << endl;
    }
}
