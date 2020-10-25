#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P43: 区間スケジューリング問題

int main() {
  int n;
  cin >> n;
  vector<P> st(n);
  // 終了時間の早い順でソートするため,tをfirstに,sをsecond
  rep(i, n) cin >> st[i].second >> st[i].first;

  sort(st.begin(), st.end());

  ll ans = 0;
  // 最後に選んだ仕事の終了時間
  ll t = 0;
  rep(i, n) {
    if (t < st[i].second) {
      ans++;
      t = st[i].first;
    }
  }

  cout << ans << endl;
  return 0;
}