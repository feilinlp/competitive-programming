#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll T;
    cin >> T;
    for (ll t=0; t<T; t++)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr+n);

        ll curr=1, ans=0, pos=0;
        while (pos < n)
        {
            if (arr[pos] >= curr)
            {
                ans+=arr[pos]-curr;
                curr++;
            }
            pos++;
        }
        cout << ans << endl;
    }
}