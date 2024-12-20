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
        vector <int> pro;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            if (a[i] != -1)
                pro.push_back(i);
        }
        
        bool possible = true;

        if (pro.size() > 0) {
            for (int i=pro[0]-1; i>=0; i--) {
                if (a[i+1] != 1)
                    a[i] = a[i+1] / 2;
                else
                    a[i] = a[i+1] * 2;
            }

            for (int i=pro[pro.size()-1]+1; i<n; i++) {
                if (a[i-1] != 1)
                    a[i] = a[i-1] / 2;
                else
                    a[i] = a[i-1] * 2;
            }

            for (int i=0; i<pro.size()-1; i++) {
                int l = pro[i];
                int r = pro[i+1];
                while (l < r) {
                    if (l == r-1 && (a[l] != a[r]/2 && a[r] != a[l]/2))
                        possible = false;

                    if (a[l] == a[r])
                        break;
                    else if (a[l] < a[r]) {
                        a[r-1] = a[r] / 2;
                        r--;
                    }
                    else {
                        a[l+1] = a[l] / 2;
                        l++;
                    }
                }

                if (a[l] == a[r]) {
                    if ((r-l)%2==1)
                        possible = false;
                    else {
                        for (int j=l+1; j<r; j++) {
                            if (j%2==l%2)
                                a[j] = a[l];
                            else
                                a[j] = a[l]*2;
                        }
                    }
                }
            }
        } else {
            for (int i=0; i<n; i++) {
                if (i%2==0)
                    a[i] = 1;
                else
                    a[i] = 2;
            }
        }


        if (possible) {
            for (int i=0; i<n; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        else
            cout << "-1\n";
    }
}
