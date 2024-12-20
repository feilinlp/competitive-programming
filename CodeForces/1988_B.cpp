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
        char a[n];
        for (int i=0; i<n; i++)
            cin >> a[i];
        
        int z = 0, o = 0;
        if (a[0] == '1')
            o++;
        else
            z++;
        for (int i=1; i<n; i++) {
            if (a[i] == '1')
                o++;
            else if (a[i] != a[i-1]) {
                z++;
            }
        }

        if (o > z)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
