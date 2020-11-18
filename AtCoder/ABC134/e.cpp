#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// deque + lower_bound

/*
    参考リンク
    ABC 134 E - Sequence Decomposing
      https://atcoder.jp/contests/abc134/tasks/abc134_e
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  deque<int> d;
  rep(i, n) {
    int p = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (p == 0) {
      d.push_front(a[i]);
    } else
      d[p - 1] = a[i];
  }
  int ans = d.size();
  cout << ans << endl;
  return 0;
}