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
		char x[105], y[105];
        cin >> x >> y;
        int length = strlen(x);
        int index = 0;
        while (index < length) {
            if (x[index] < y[index]) {
                swap(x[index], y[index]);
                break;
            }
            else if (x[index] > y[index]) {
                break;
            }
            index += 1;
        }
        for (int j=index + 1; j<length; j++) {
            if (x[j] > y[j])
                swap(x[j], y[j]);
        }
        cout << x << endl << y << endl;
	}
}
