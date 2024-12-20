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
        int l;
        cin >> l;
        int mod[l];
        for (int i=1; i<l; i++) {
            cin >> mod[i];
        }

        int a[l];
        a[0] = mod[1] + 1;
        for (int i=1; i<l; i++) {
            if (i + 1 < l) {
                a[i] = (mod[i+1] / a[i-1] + 1) * a[i-1] + mod[i];
            }
            else {
                a[i] = mod[i];
            }
        }

        for (int i=0; i<l; i++) cout << a[i] << " ";
        cout << endl;
    }
}
