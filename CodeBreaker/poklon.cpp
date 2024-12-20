#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long llint;
typedef pair <int, int> pii;

const int MAXN = 1 << 20;

int n, q;

vector <pii> T[MAXN]; //segtree
int a[MAXN];
int ls[MAXN], rs[MAXN];
int left[MAXN];
int right[MAXN];
int ans[MAXN];

//update segtree
void update (int x, int l, int r, int L, int v) { // x index of segtree l, r range L left query, v index of query
  if (L > r || L < l) return; // L not within range
  T[x].push_back({rs[v], v}); // right query & index of query
  int mid = (l + r) / 2;
  if (l == r) return;
  update(x * 2, l, mid, L, v); // update children
  update(x * 2 + 1, mid+1, r, L, v);
}

void query_update (int x, int l, int r, int L, int R, int p1, int p2) { //x index of segtree l, r range, L, R query, p1 after, p2 after after
  if (L > r || R < l) return; // Query not within range
  if (l >= L && r <= R) { // to signal that when is 2 or when is more
    T[x].push_back({p1, -1});
    T[x].push_back({p2, -2});
    return;
  }
  int mid = (l + r) / 2;
  query_update(x * 2, l, mid, L, R, p1, p2);
  query_update(x * 2 + 1, mid+1, r, L, R, p1, p2);
}

void solve (int x, int l, int r) {
  sort(T[x].begin(), T[x].end()); // sort
  int cnt = 0;
  for (auto v: T[x]) { // go through T on index x
    if (v.second == -1) ++cnt;
    else
    if (v.second == -2) --cnt;
    else ans[v.second] += cnt; // query in that range is updated
  }
  if (l == r) return;
  int mid = (l+r) / 2;
  solve(x*2, l, mid);
  solve(x*2+1, mid+1, r);
}

int main (void){
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < q; ++i) {
    scanf("%d%d", &ls[i], &rs[i]);
    --ls[i]; --rs[i]; // index start 0
    update(1, 0, n-1, ls[i], i); // update content of segtree
  }
  map <int, int> M;
  for (int i = 0; i < n; ++i) {
    int pos = -1;
    if (M.count(a[i])) pos = M[a[i]]; // check if map with index of number exists (map consists of the index of the number)
    left[i] = pos; //same number before this
    M[a[i]] = i; // replace with current position
  }
  M.clear(); //M is cleared to do similar process, but same number after this
  for (int i = n-1; i >= 0; --i) {
    int pos = n;
    if (M.count(a[i])) pos = M[a[i]];
    right[i] = pos;
    M[a[i]] = i;
  }
  right[n] = n;

  for (int i = 0; i < n; ++i) {
    int rpos = right[i]; 
    if (rpos == n) continue; // if that number is the last in the sequence, skip
    query_update(1, 0, n-1, left[i] + 1, i, rpos, right[rpos]); // update query for???
  }

  solve(1, 0, n-1); // solve
  for (int i = 0; i < q; ++i) // just print
    printf("%d\n", ans[i]);

  return 0;
}
