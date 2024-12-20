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
		int n, m, k;
		cin >> n >> m >> k;
		int div = (n-n%m) / m;
		if (n%m != 0) 
			div += 1;
		if (k>=n-div)
			cout << "NO\n";
		else
			cout << "YES\n"; 
	}
}
