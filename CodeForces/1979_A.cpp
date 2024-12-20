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
        
        int ans = 1000000000;
        for (int i=0; i<n-1; i++) {
            ans = min(ans, max(a[i], a[i+1]));
        }
        cout << ans - 1 << endl;
    }
}
