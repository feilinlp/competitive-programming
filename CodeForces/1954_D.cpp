#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll f(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> arr(n), sum(5005);
    for (ll i=0; i<n; i++)
        sum[i] = 0;
    sum[0] = 1;

    ll largest = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    ll ans = 0;
    for (ll i=0; i<n; i++) {
        for (ll j=arr[i]+1; j<=largest; j++) {
            ll add = j - arr[i];
            if (add % 2) add += 1;
            add /= 2;
            ans = (ans + sum[j] * add) % MOD;
        }
        for (ll j = largest; j>=0; j--)
            sum[j + arr[i]] = (sum[j+arr[i]] + sum[j]) % MOD;
        largest += arr[i];
    }

    for (ll i = 0; i < n; i++) {
        ans = (ans + (arr[i] * f(2, i)) % MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}
