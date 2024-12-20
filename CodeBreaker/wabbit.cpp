#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

bool comp (ll a, ll b)
{
    return a > b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here

    ll n, q, k;
    cin >> n >> q >> k;
    ll p[n];
    for (ll i=0; i<n; i++)
    {
        cin >> p[i];
    }
    ll x[q];
    for (ll i=0; i<q; i++)
        cin >> x[i];
    
    sort(p, p+n , comp);
    for (ll i=1; i<n; i++)
    {
        p[i]+=p[i-1];
    }

    // for (int i=0; i<n; i++) 
    //     cout << p[i] << endl;

    k++;
    // cout << k << endl;
    for (ll i=0; i<q; i++)
    {
        ll bonus=x[i]/k;
        // cout << x[i] << bonus << endl;
        if (bonus > 0)
        	cout << p[x[i]-1] + p[bonus-1] << endl;
        else
        	cout << p[x[i]-1] << endl;
    }
}
