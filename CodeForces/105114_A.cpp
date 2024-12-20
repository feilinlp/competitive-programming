#include <bits/stdc++.h>
#define f first
#define s second


using namespace std;
using ll = long long;

bool qsort(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b) {
    if (a.f.s == b.f.s)
        return a.f.f < b.f.f;
    
    return a.f.f > b.f.s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
    cin >> n >> q;
    int array[n];
    for (int i=0; i<n; i++) {
        cin >> array[i];
    }

    pair < pair <int, int>, int> query[q];
    for (int i=0; i<q; i++) {
        cin >> query[i].f.f >> query[i].f.s;
        query[i].s = i;
    }

    sort(query, query + q, qsort);
}
