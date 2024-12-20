#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function.
ll binarySearch(ll low, ll high, ll x)
{
    ll mid;
    while (low <= high) {
        mid = low + (high - low) / 2;

        // If x greater, ignore left half
        if (mid * mid < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    return high;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//code here

    ll t;
    cin >> t;
    for (ll i=0; i<t; i++) {
        ll r;
        cin >> r;
        //Find for < r
        ll count1 = (2*r-1)*(2*r-1);
        for (ll j=1; j<r; j++) {
            ll limit = binarySearch(0, j, r*r - j*j);
            // cout << "limit " << limit << endl;
            if (j-limit>0)
                count1 -= (2*(j-limit)-1)*4;
        }

        r+=1;
        ll count2 = (2*r-1)*(2*r-1);
        for (ll j=1; j<r; j++) {
            ll limit = binarySearch(0, j, r*r - j*j);
            if (j-limit>0)
                count2 -= (2*(j-limit)-1)*4;
        }
        cout << count2-count1 << endl;
    }
}
