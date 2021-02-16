#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 80 D - Recording
      https://atcoder.jp/contests/abc080/tasks/abc080_d
*/

// 連続して流れる番組はまとめてしまう方が良い
// テレビ番組は[L[i],R[i])で放送されるが、録画機の切り替えに時間が必要な事を考えると、
// [L[i],R[i]]だけ録画機を独占していることになるので、どちらも閉区間で塗る

int imos[30][101010];

int main() {
  int n, c;
  cin >> n >> c;
  rep(i, n) {
    int a, b, ci;
    cin >> a >> b >> ci;
    a--;
    ci--;
    imos[ci][a]++;
    imos[ci][b]--;
  }
  rep(i, c) rep(j, 100100) imos[i][j + 1] += imos[i][j];
  rep(i, c) rep(j, 100100) if (imos[i][j]) imos[i][j] = 1;

  int ans = 0;
  rep(i, 100100) {
    int cnt = 0;
    rep(j, c) cnt += imos[j][i];
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}