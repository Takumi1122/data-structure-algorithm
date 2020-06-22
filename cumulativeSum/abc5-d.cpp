#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<vector<ll> > d(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> d[i][j];

  // 累積和
  vector<vector<ll> > s(n + 1, vector<ll>(n + 1, 0));
  rep(i, n) rep(j, n) s[i + 1][j + 1] =
      s[i][j + 1] + s[i + 1][j] - s[i][j] + d[i][j];

  // すべての長方形区域の面積を集計
  vector<ll> val(n * n + 1,
                 0);  // val[v] := 面積が v の長方形領域の総和の最大値
  for (int x1 = 0; x1 < n; ++x1) {
    for (int x2 = x1 + 1; x2 <= n; ++x2) {
      for (int y1 = 0; y1 < n; ++y1) {
        for (int y2 = y1 + 1; y2 <= n; ++y2) {
          ll area = (x2 - x1) * (y2 - y1);
          ll sum = s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
          val[area] = max(val[area], sum);
        }
      }
    }
  }

  // ちゃんと集計,  val[v] := 面積が v 「以下」の長方形領域の総和の最大値
  for (int v = 0; v < n * n; ++v) val[v + 1] = max(val[v + 1], val[v]);

  // クエリに答える
  int q;
  cin >> q;
  rep(i, q) {
    ll p;
    cin >> p;
    cout << val[p] << endl;
  }
}