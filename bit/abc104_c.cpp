#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// bit全探索 + Greedy

// 全完する難易度帯を2^d通り決め打ちする
// ・それだけでg点に到達する場合はそれでOK
// ・それだけでは到達しない場合は,全完対象でないもののうちGreedyに高難易度から順に解いて行けばOK

/*
    参考リンク
    ABC 104 C - All Green
      https://atcoder.jp/contests/abc104/tasks/abc104_c
*/

int main() {
  ll d, g;
  cin >> d >> g;
  vector<ll> p(d), c(d);
  rep(i, d) cin >> p[i] >> c[i];

  ll ans = 1 << 29;
  for (int bit = 0; bit < (1 << d); ++bit) {
    ll sum = 0;
    ll num = 0;

    rep(i, d) {
      if (bit & (1 << i)) {
        sum += c[i] + p[i] * 100 * (i + 1);
        num += p[i];
      }
    }

    if (sum >= g) {
      ans = min(ans, num);
    } else {
      for (int i = d - 1; i >= 0; --i) {
        if (bit & (1 << i)) continue;
        rep(j, p[i]) {
          if (sum >= g) break;
          sum += 100 * (i + 1);
          ++num;
        }
      }
      ans = min(ans, num);
    }
  }

  cout << ans << endl;
  return 0;
}