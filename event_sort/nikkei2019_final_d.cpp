#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// イベントソート

/*
    参考リンク
    全国統一プログラミング王決定戦本戦 D - Deforestation
      https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d
*/

int main() {
  int n, m;
  cin >> n >> m;
  // ins[i] := iを区間の始点とするような時刻tの集まり. era[i]も同様
  vector<vector<int> > ins(n + 1), era(n + 1);
  rep(i, m) {
    int t, l, r;
    cin >> t >> l >> r;
    --l;
    ins[l].push_back(t);
    era[r].push_back(t);
  }

  // いもす法
  set<int> se;  // その点その点についての時刻イベントを平面走査していく
  se.insert(0);  // 番兵
  ll ans = 0;
  for (int i = 0; i <= n; ++i) {
    for (auto t : ins[i]) se.insert(t);
    for (auto t : era[i]) se.erase(t);
    ans += *prev(se.end());
  }

  cout << ans << endl;
  return 0;
}