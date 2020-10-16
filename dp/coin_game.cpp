#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P272: コインのゲーム1

int main() {
  int x, k;
  cin >> x >> k;
  vector<int> a(k);
  rep(i, k) cin >> a[i];

  vector<bool> win(x + 1);
  for (int i = 1; i <= x; i++) {
    win[i] = false;
    rep(j, k) {
      if (i - a[j] >= 0) win[i] = (win[i] || !win[i - a[j]]);
    }
  }

  if (win[x])
    cout << "Alice" << endl;
  else
    cout << "Bob" << endl;
  return 0;
}