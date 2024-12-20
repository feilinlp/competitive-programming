#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
    int a, b, c;

    node(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }

    bool operator<(const node& other) const {
        if (a == other.a) {
            if (b == other.b) {
                return c < other.c;
            }
            return b < other.b;
        }
        return a < other.a;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<node> first, second, third;
        for (int i = 0; i < n - 2; i++) {
            node x(arr[i], arr[i + 1], arr[i + 2]);
            node y(arr[i + 1], arr[i + 2], arr[i]);
            node z(arr[i + 2], arr[i], arr[i + 1]);
            first.push_back(x);
            second.push_back(y);
            third.push_back(z);
        }

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());
        sort(third.begin(), third.end());

        ll ans = 0;
        ll curr = 0;
        ll prev = 0;

        for (int i = 1; i < first.size(); i++) {
            if (first[i].a == first[i - 1].a && first[i].b == first[i - 1].b) {
                curr++;
                if (first[i].c != first[i - 1].c) {
                    prev=curr;
                    ans += curr;
                } else {
                    ans += prev;
                }
            } else {
                curr = 0;
                prev = 0;
            }
        }
        // cout <<"ans"<< ans << endl;

        curr = 0;
        prev = 0;
        for (int i = 1; i < second.size(); i++) {
            if (second[i].a == second[i - 1].a && second[i].b == second[i - 1].b) {
                curr++;
                if (second[i].c != second[i - 1].c) {
                    prev=curr;
                    ans += curr;
                } else {
                    ans += prev;
                }
            } else {
                prev = 0;
                curr = 0;
            }
        }
        // cout <<"ans"<< ans << endl;

        curr = 0;
        prev = 0;
        for (int i = 1; i < third.size(); i++) {
            if (third[i].a == third[i - 1].a && third[i].b == third[i - 1].b) {
                curr++;
                if (third[i].c != third[i - 1].c) {
                    prev=curr;
                    ans += curr;
                } else {
                    ans += prev;
                }
            } else {
                prev = 0;
                curr = 0;
            }
        }

        cout << ans << endl;
    }
}
