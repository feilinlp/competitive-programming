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
        int first[n], second[n];
        for (int i=0; i<n; i++) {
            cin >> first[i];
        }

        int f = 0, s = 0;
        for (int i=0; i<n; i++) {
            cin >> second[i];
            if (first[i] > second[i] && first[i] == 1) {
                f++;
            }
            else if (second[i] > first[i] && second[i] == 1) {
                s++;
            }
        }

        for (int i=0; i<n; i++) {
            if (first[i] == second[i]) {
                if (first[i] == 1) {
                    if (f < s)
                        f++;
                    else
                        s++;
                }
                else if (first[i] == -1){
                    if (f < s)
                        s--;
                    else
                        f--;
                }
            }
        }
        
        cout << min(f, s) << endl;
    }
}
