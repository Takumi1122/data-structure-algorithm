#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P281: コインのゲーム2

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep(i, k) cin >> a[i];

  vector<int> x(n);
  int max_x = 0;
  rep(i, n) {
    cin >> x[i];
    max_x = max(max_x, x[i]);
  }

  // grundy数を求める
  vector<int> grundy(max_x + 1);
  for (int i = 1; i <= max_x; i++) {
    set<int> s;
    rep(j, k) {
      if (a[j] <= i) s.insert(grundy[i - a[j]]);
    }

    int g = 0;
    while (s.count(g) != 0) g++;
    grundy[i] = g;
  }

  // 勝敗を判定
  int xr = 0;
  rep(i, n) xr ^= grundy[x[i]];

  if (xr != 0)
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}