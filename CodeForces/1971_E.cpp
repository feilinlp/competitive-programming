#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here

    ll t;
    cin >> t;
    for (ll i=0; i<t; i++){
        ll n,k,q;
        cin >> n >> k>>q;
        vector <ll> a(k), b(k);
        for (ll j=0; j<k; j++)
            cin >> a[j];
        for (ll j=0; j<k; j++)
            cin >> b[j];
        
        for (ll j=0; j<q; j++) {
            ll x;
            cin >> x;
            ll index = upper_bound(a.begin(), a.end(), x) - a.begin() -1;
            if (index < 0)
                index=0;
            // cout << "index " << index << endl;
            if (a[index] <= x)
                cout << b[index] + ((x - a[index]) * (b[index+1]-b[index])) / (a[index+1]-a[index]) << " ";
            else
                cout << (x * b[index]) / a[index] << ' ';
        }
        cout << endl;
    }
}
