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
        int n, k;
        cin >> n >> k;
        cout << (n - 1) * k + 1 << endl;
    }
}
