#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int prime[4000100];
bool multiple[4000100];

int search(int n) {
    int l = 1, r = 10000, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (mid % 2) {
            if (mid * (mid + 1) / 2 > n) {
                r = mid - 1;
            } 
            else if (mid * (mid + 1) / 2 == n) {
                return mid;
            }
            else {
                l = mid + 1;
            }
        } 
        else {
            if (mid * mid / 2 + 1 > n) {
                r = mid - 1;
            }
            else if (mid * mid / 2 + 1 == n) {
                return mid;
            }
            else {
                l = mid + 1;
            }
        }
    }

    return mid;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    //Initialise list of prime numbers
    int curr = 0;
    for (int i=2; i<1000000; i++) {
        if (!multiple) {
            prime[curr] = i;
            curr++;
            for (int j=i; i<4000100; j += i) {
                multiple[j] = true;
            } 
        }
    }

	int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n;
        cin >> n;
        int p = search(n);
        
    }
}
