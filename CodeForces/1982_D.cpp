#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) 
{ 
    if (a > b) {
        ll temp = a;
        a = b;
        b = temp;
    }

    if (a == 0)
        return b;

    return gcd(b % a, a);
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll T;
    cin >> T;
    for (ll test=0; test<T; test++) {
        ll n, m, k;
        cin >> n >> m >> k;
        ll a[n+5][m+5];
        char t[n+5][m+5];
        for (ll i=0; i<n; i++) {
            for (ll j=0; j<m; j++) {
                cin >> a[i][j];
            }
        }

        ll snow = 0, no = 0;
        for (ll i=0; i<n; i++) {
            char help[m+5];
            cin >> help;
            for (ll j=0; j<m; j++) {
                t[i][j] = help[j];
                if (t[i][j] == '0')
                    snow += a[i][j];
                else
                    no += a[i][j];
            }
        }

        ll row[n][m-k+1];
        for (ll i=0; i<n; i++) {
            row[i][0] = 0;
            for (int j=0; j<k; j++) {
                if (t[i][j] == '0')
                    row[i][0]++;
                else    
                    row[i][0]--;
            }

            for (ll j=1; j<m-k+1; j++) {
                row[i][j] = row[i][j-1];
                if (t[i][j-1] == '0')
                    row[i][j]--;
                else
                    row[i][j]++;
                
                if (t[i][j+k-1]=='0')
                    row[i][j]++;
                else
                    row[i][j]--;
            }
        }

        ll diff = snow - no;
        ll plot[n-k+6][m-k+6];

        for (int i=0; i<m-k+1; i++) { // col
            plot[0][i] = 0;
            for (int j=0; j<k; j++) { // row
                plot[0][i] += row[j][i];
            }
        }

        for (int i=1; i<n-k+1; i++) {
            for (int j=0; j<m-k+1; j++) {
                plot[i][j] = plot[i-1][j] - row[i-1][j] + row[i+k-1][j];
            }
        }


        bool pos = false;
        ll mul[n*m];
        ll muli=0;

        if (diff == 0)
            pos = true;

        if (diff < 0)
            diff *= -1;

        for (ll i=0; i<n-k+1; i++) {
            if (pos)
                break;

            for (ll v=0; v<m-k+1; v++) {
                if (plot[i][v] < 0)
                    plot[i][v] *= -1;
                
                // cout << i << " " << v << " " << plot[i][v] << endl;

                if (plot[i][v] != 0 && diff % plot[i][v] == 0) {
                    pos = true;
                    break;
                } 
                // cout << __LINE__ << endl;
                
                bool insert = true;
                if (plot[i][v] != 0) {
                    for (ll l=0; l<muli; l++) {
                        if (plot[i][v] == mul[l]){
                            insert = false;
                            break;
                        } else if (gcd(plot[i][v], mul[l]) == 1) {
                            pos = true;
                            break;
                        } else if (plot[i][v] != mul[l] && diff % gcd(plot[i][v], mul[l]) == 0) {
                            pos = true;
                            break;
                        } else {
                            mul[l] = gcd(plot[i][v], mul[l]);
                            insert = false;
                        }
                    }

                    if (insert) {
                        mul[muli] = plot[i][v];
                        muli++;
                    }
                }

                if (pos)
                    break;
            }
        }

        if (pos)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}
