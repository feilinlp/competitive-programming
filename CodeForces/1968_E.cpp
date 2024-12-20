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
        int n;
        cin >> n;
        cout << "1 1\n";
        cout << n << " " << n << endl;
        for (int j=1; j<n-1; j++) {
            if (j%4==1) {
                cout << 1 + j << " 1\n";
            }
            else if (j%4==2) {
                cout << n - j << " " << n << endl;
            }
            else if (j%4 == 3) {
                cout << "1 " << 1+j << endl;
            }
            else
                cout << n << " " << n - j << endl;
        }
    }
}
