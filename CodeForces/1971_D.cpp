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
        string s;
        cin >> s;
        int count = 1;
        bool found = false;
        for (int j=1; j<s.length(); j++) {
            if (s[j] != s[j-1]) {
                count++;
            }

            if (!found && s[j]=='1' && s[j-1]=='0')
                found = true;
        }
        if (found)
            count--;
        
        cout << count << endl;
    }
}
