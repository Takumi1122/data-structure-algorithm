#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 最小本数の串で全ての区間を串刺しにせよ = 区間スケジューリング問題
// 双対問題

/*
    参考リンク
    ABC 103 D - Islands War
      https://atcoder.jp/contests/abc103/tasks/abc103_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> ab(m);
  rep(i, m) cin >> ab[i].second >> ab[i].first;

  sort(ab.begin(), ab.end());

  ll ans = 0;
  ll t = 0;
  rep(i, m) {
    if (t <= ab[i].second) {
      ans++;
      t = ab[i].first;
    }
  }

  cout << ans << endl;
  return 0;
}