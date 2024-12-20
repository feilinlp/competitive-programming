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
        char pw[l];
        cin >> pw;
        bool strong = true;
        bool letter = false;
        for (int i=0; i<l; i++) {
            if (pw[i]>='a' && pw[i]<='z')
            {
                if (letter && pw[i] < pw[i-1])
                    strong = false;
                letter = true;
            } else if (pw[i] >= '0' && pw[i] <= '9')
            {
                if (i > 0 && pw[i] < pw[i-1])
                    strong = false;
                if (letter)
                    strong = false;
            } else {
                strong = false;
            }
        }
        if (strong)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
