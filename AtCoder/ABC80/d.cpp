#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 連続して流れる番組はまとめてしまう方が良い
// テレビ番組は[L[i],R[i])で放送されるが、録画機の切り替えに時間が必要な事を考えると、
// [L[i],R[i]]だけ録画機を独占していることになるので、どちらも閉区間で塗る

int main() {
  int n, c;
  cin >> n >> c;
  vector<map<int, int>> vm(c);
  rep(i, n) {
    int s, t, ci;
    cin >> s >> t >> ci;
    ci--;
    vm[ci][s]++;
    vm[ci][t]--;
  }

  vector<int> st(100100);
  rep(i, c) {
    for (auto p : vm[i]) {
      if (p.second == -1) {
        st[p.first + 1] += p.second;
      } else {
        st[p.first] += p.second;
      }
    }
  }

  rep(i, 100010) st[i + 1] += st[i];
  int ans = 0;
  rep(i, 100010) ans = max(ans, st[i]);

  cout << ans << endl;
  return 0;
}