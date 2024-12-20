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
        int length;
        cin >> length;
        char s[length+5];
        cin >> s;
        map <char, int> avail;
        vector <char> uniq;
        for (int l=0; l<length; l++) {
            if (avail.find(s[l]) == avail.end()) {
                avail[s[l]] = 1;
                uniq.push_back(s[l]);
            }
            // cout << __LINE__ << endl;
        }
        // cout << __LINE__ << endl;
        sort(uniq.begin(), uniq.end());

        for (int i=0; i<uniq.size(); i++) {
            avail[uniq[i]] = i;
            // cout << uniq[i] << avail[uniq[i]];
        }
        int r = uniq.size()-1;
        for (int i=0; i<length; i++) {
            // cout << avail[s[i]] << endl;
            cout << uniq[r - avail[s[i]]];
        }
        cout << endl;
    }
}
