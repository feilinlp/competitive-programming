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
        char s[n];
        cin >> s;

        int one = 0, zero = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '0')
                zero++;
            else
                one++;
        }

        bool poss = true;
        if (one % k != 0 | zero % k != 0)
            poss = false;
        
        if (poss) {
            int start = 0;
            int wrong = -1;
            for (int i=1; i<n; i++) {
                if (s[i] != s[start]) {
                    if (i - start != k) {
                        wrong = start;
                        break;
                    }

                    start = i;
                }
            }
            // cout << "wrong " << wrong << endl;
            if (wrong == -1) {
                bool pass = true;
                for (int i=1; i<k; i++) {
                    if (s[i] != s[i-1])
                        pass = false;
                }

                for (int i=k; i<n; i++) {
                    if (s[i] == s[i-k])
                        pass = false;
                }

                if (pass)
                    cout << n << endl;
                else
                    cout << "-1\n";
            }
            else {
                int back = n-1;
                while (s[back] == s[wrong]) {
                    back--;
                } // back is the different one

                int count = k - (n - (back + 1));
                // cout << t << " count " << count << endl;
                if (count < 0)
                    cout << "-1\n";
                else {
                    int p = wrong + count; // index 1
                    char check[n];
                    for (int i=0; i<n-p; i++) {
                        check[i] = s[i + p];
                    }
                    for (int i=n-1; i>=n-p; i--) {
                        check[i] = s[n - i - 1];
                    }

                    // cout << "p " << p << endl;
                    // cout << "check ";
                    // for (int i=0; i<n; i++)
                    //     cout << check[i];
                    // cout << endl;

                    bool pass = true;
                    for (int i=1; i<k; i++) {
                        if (check[i] != check[i-1])
                            pass = false;
                    }

                    for (int i=k; i<n; i++) {
                        if (check[i] == check[i-k])
                            pass = false;
                    }

                    if (pass)
                        cout << p << endl;
                    else
                        cout << "-1\n";
                }
            }
        }
        else 
            cout << "-1\n";
    }
}
