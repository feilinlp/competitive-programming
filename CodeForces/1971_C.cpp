#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here

	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		int a, b, c, d;
		cin >> a >>b >>c>>d;
		if (a>b) {
			int temp=a;
			a=b;
			b=temp;
		}
		if (c>d) {
			int temp=c;
			c=d;
			d=temp;
		}
		if (a<c && c<b && (d > b || d < a)) {
			cout << "YES\n";
		}
        else if (a<d && d<b && (c > b || c < a)){
			cout << "YES\n";
		}
		else
			cout << "NO\n";
	}
}
