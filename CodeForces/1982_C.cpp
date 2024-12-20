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
        int n, l, r;
        cin >> n >> l >> r;
        int cards[n];
        for (int i=0; i<n; i++) {
            cin >> cards[i];
        }

        int start = 0, curr = 0, sum = 0, count = 0;
        while (curr < n) {
            sum += cards[curr];
            while (sum > r) {
                sum -= cards[start];
                start++;
            }
            curr++;
            if (l <= sum && sum <= r) {
                count++;
                start = curr;
                sum = 0;
            }
        }
        cout << count << endl;
    }
}
