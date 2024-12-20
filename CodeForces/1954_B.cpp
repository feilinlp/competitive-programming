#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		int n;
        cin >> n;
        int arr[n];
        int prev = -1;
        for (int j=0; j<n; j++) {
            cin >> arr[j];
        }
        int left=-1, right=-1;
        int skip = 300005;
        for (int j=0; j<n; j++) {
            if (arr[j] != arr[n-1]) {
                left = j;
                break;
            }
        }
        for (int j=n-1; j>=0; j--) {
            if (arr[j] != arr[0]) {
                right = n - 1 - j ;
                break;
            }
        }
        for (int j=0; j<n; j++) {
            if (arr[j] != arr[0]) {
                if (prev != -1) 
                    skip = min(skip, j-prev - 1);
                prev = j;
            }
        }

        if (left == -1)
            cout << "-1\n";
        else
            cout << min(skip,min(left, right)) << endl;
	}
}
