#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Recursive function to return gcd of a and b  
long long gcd(long long int a, long long int b) 
{ 
  if (b == 0) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
long long lcm(int a, int b) 
{ 
    return (a / gcd(a, b)) * b; 
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n;
        cin >> n;
        int a[n];
        ll mul = 1;
        for (int i=0; i<n; i++) {
            cin >> a[i];
            mul = lcm(mul, a[i]); 
        }

        int ans[n];
        ll sum = 0;
        for (int i=0; i<n; i++) {
            ans[i] = mul / a[i];
            sum += ans[i];
        }

        if (sum < mul) {
            for (int i=0; i<n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
        else 
            cout << "-1\n";
    }
}
