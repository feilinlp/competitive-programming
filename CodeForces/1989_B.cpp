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
        string a, b;
        cin >> a >> b;

        int pos[b.length()]; // Position of the character in b
        int start = 0, curr = 0, length = 0;
        pos[0] = a.find(b.substr(0, 1));
        if (pos[0] != -1)
            curr++; // Checks which character now
        while (start < b.length()) {
            while (curr == 0) { // If current start does not exist, then put at the front
                start++;

                if (start >= b.length())
                    break;

                pos[start] = a.find(b.substr(start, 1));

                if (pos[start] != -1)
                    curr++;
            }

            if (start + curr < b.length()) {
                int temp = a.substr(pos[start+curr-1]+1).find(b.substr(start+curr,1));
                pos[start+curr] = pos[start+curr-1] + 1 + temp;
                if (temp!=-1) {
                    curr++;
                } else {
                    // cout << length << " " << curr << endl;
                    length = max(length, curr);
                    curr = 0;
                    start++;
                    if (start < b.length()) {
                        pos[start] = a.find(b.substr(start, 1)); // Reset the current sequence
                        if (pos[start] != -1)
                            curr++;
                    }
                }
            }   

            if (start + curr >= b.length()) {
                length = max(length, curr); // Take max overlapping characters
                curr = 0;
                start++;
                if (start < b.length()) {
                    pos[start] = a.find(b.substr(start, 1)); // Reset the current sequence
                    if (pos[start] != -1)
                        curr++;
                }
            }          
        }

        cout << a.length() + b.length() - length << endl;
    }
}
