#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

// X <= t (mod C) < X + Y
// P <= t (mod D) < P + Q
// 最小のtを求める

// Y,Q <= 500 より 全探索

// crt: O(n*loglcm(m[i])) nは配列の長さ

/*
    参考リンク
    ABC 193 E - Oversleeping
      https://atcoder.jp/contests/abc193/tasks/abc193_e
*/

const ll INF = 3e18;

void solve() {
  int x, y, p, q;
  cin >> x >> y >> p >> q;

  ll C = (x + y) * 2;
  ll D = p + q;
  ll t = INF;

  for (ll a = x; a < x + y; ++a) {
    for (ll b = p; b < p + q; ++b) {
      // t ≡ a (mod C)
      // t ≡ b (mod D)
      // 上記の条件を満たすtをcrtで求める
      auto r = crt({a, b}, {C, D});
      // crt: 答えがない場合は(0,0)を返す
      if (r.second == 0) continue;
      t = min(t, r.first);
    }
  }

  if (t == INF)
    cout << "infinity" << endl;
  else
    cout << t << endl;
}

int main() {
  int T;
  cin >> T;
  rep(ti, T) solve();
  return 0;
}