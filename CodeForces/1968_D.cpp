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
        int n, k, b, s;
        cin >> n >> k >> b >> s;
        b--;
        s--;
        int p[n], a[n];
        for (int i=0; i<n; i++) {
            cin >> p[i];
            p[i]-=1;
        }
        for (int i=0; i<n; i++) cin >> a[i];

        ll bodya=0, sasha=0;
        ll tb=0, ts=0;
        for (int i=0; i<min(k, n); i++) {
            tb += a[b];
            ts += a[s];
            if (a[p[b]]<=a[b]) {
                bodya = max(bodya, tb + (k-i-1) * a[b]);
                // cout << b << endl;
            }
            if (a[p[s]]<=a[s]) {
                sasha = max(sasha, ts + (k-i-1) * a[s]);
            }
            b = p[b];
            s = p[s];
        }
        // cout << bodya << " " << sasha << endl;
        if (bodya > sasha) cout << "Bodya\n";
        else if (bodya < sasha) cout << "Sasha\n";
        else cout << "Draw\n";
    }
}
