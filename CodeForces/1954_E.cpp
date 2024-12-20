#include <iostream>
#include <algorithm>
#include <set>
#define f first
#define s second

using namespace std;

int divide(int a, int i) {
    return (a + (i - a%i)%i)/i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[100005], cut[100005];
    int up=0;
    int asize = n, cuts=0;

    for (int i=0; i<n; i++) {
        cin >> a[i];
        up = max(up, a[i]);
    }

    pair <int, int> reduce[100005];
    int reduces = 0;

    while (true) {
        // cout << "a ";
        // for (int i=0; i<asize; i++)
        //     cout << a[i] << " ";
        // cout << endl;

        if (asize == 1 || (asize == 2 && a[0] == a[1])) {
            reduce[reduces] = make_pair(a[0], a[0]);
            reduces += 1;
            break;
        }

        int start = a[0];
        int prev = a[1];
        bool increase = a[1] >= a[0];

        cuts = 0;
        cut[cuts] = start;
        cuts += 1;

        // Get the values for cut, cut down all intermediate values
        for (int i=2; i<asize; i++) {
            if ((increase && a[i] < prev) || (!increase && a[i] > prev)) {
                cut[cuts] = prev;
                cuts += 1;
                start = prev;
                increase = !increase;
            }
            prev = a[i];
        }

        cut[cuts] = prev;
        cuts += 1;

        // cout << "cut ";
        // for (int i=0; i<cuts; i++)
        //     cout << cut[i] << " ";
        // cout << endl;

        // Process values in cut for reduce
        int right;
        bool even = true;

        if (cut[0] > cut[1]) {
            even = false;
            reduce[reduces] = make_pair(cut[0] - cut[1], cut[0]);
            reduces += 1;
        }

        for (int i=1; i<cuts; i++) {
            if (cut[i] >= cut[i-1]) {
                if (i == cuts-1)
                    right = i-1;
                else
                    right = i+1;

                int maxi = max(cut[right], cut[i-1]);
                reduce[reduces] = make_pair(cut[i] - maxi, cut[i]);
                reduces += 1;
            }
        }

        asize = 0;
        if (even) {
            for (int i=0; i<cuts; i+=2) {
                a[asize] = cut[i];
                asize += 1;
            }
        } else {
            for (int i=1; i<cuts; i+=2) {
                a[asize] = cut[i];
                asize += 1;
            }
        }

        // cout << "reduce ";
        // for (int i=0; i<reduce.size(); i++)
        //     cout << reduce[i].f << " " << reduce[i].s << ", ";
        // cout << endl;
    }
    
    // cout << "reduce ";
    // for (int i=0; i<reduce.size(); i++)
    //     cout << reduce[i].f << " " << reduce[i].s << ", ";
    // cout << endl;

    // Calculate answer from the differences
    for (int i=1; i<=up; i++) {
        int ans = 0;
        for (int j=0; j<reduces; j++) {
            ans += divide(reduce[j].f - (i - (reduce[j].s- reduce[j].f) % i)% i, i);
        }
        cout << ans << " ";
    }
    cout << endl;
}
