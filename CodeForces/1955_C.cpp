#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cstring>
#include <math.h>
#include <numeric>
#define ll long long

using namespace std;

int main(){
	ll t;
    scanf("%lld", &t);
    for (ll i=0; i<t; i++){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        ll arr[n];
        for (ll j=0; j<n; j++){
            scanf("%lld", &arr[j]);
        }
        ll count = 0;
        ll left = 0, right = n-1;
        bool start = true;
        while (k > 0 && count < n-1){
            if (!start) {
                arr[right] -= 1;
                k -= 1;
                start = true;
            }

            if (arr[left] <= arr[right]){
                k -= 2*arr[left] - 1;
                arr[right] -= arr[left] - 1;
                left += 1;
                count += 1;
                start = false;
            }
            else
            {
                k -= 2*arr[right];
                arr[left] -= arr[right];
                right -= 1;
                count += 1;
            }
        }
        if (k < 0) {
            count -= 1;
        }
        else if (k >= arr[left]) {
            count += 1;
        }
        printf("%lld\n", count);
    }
}
