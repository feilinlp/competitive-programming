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
        int n, q;
        cin >> n >> q;
        int arr[n], val[n];
        for (int j=0; j<n; j++){
            cin >> arr[j];
            if (j==0)
                val[j] = arr[j];
            else
                val[j] = val[j-1] ^ arr[j];
        }
        // for (int j=0 ;j<n; j++)
        //     cout << val[j];
        for (int j=0; j<q; j++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            int x = val[b];
            if (a != 0)
                x = x ^ val[a-1];
            // cout << "x " << x << endl;
            
            if (x == 0) {
                cout << "YES\n";
            }
            else {
                int curr = 0;
                for (int k=0; k<n-2; k++)
                {
                    curr = curr ^ arr[k];
                    if (curr == x) {
                        break;
                    }
                }
                if (curr == x) {
                    cout << "YES\n";
                }
                else
                    cout << "NO\n";
            }
        }

    }
}
