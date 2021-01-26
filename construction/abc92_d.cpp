#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// まずどのくらい余裕があるのかを概算
// この問題だと市松模様に塗ることで A = B = 5000が達成できる
// A,B <= 500 は余裕があることがわかる

// 構築問題

/*
    参考リンク
    ABC 92 D - Grid Components
      https://atcoder.jp/contests/abc092/tasks/arc093_b
*/

bool ans[100][100];

int main() {
  int a, b;
  cin >> a >> b;

  rep(i, 50) rep(j, 100) ans[i][j] = true;
  for (int i = 50; i < 100; i++) rep(j, 100) ans[i][j] = false;

  int nowa = 1;
  while (nowa < a) {
    for (int i = 1; i < 100; i += 2) {
      for (int j = 1; j < 100; j += 2) {
        ans[i][j] = false;
        nowa++;
        if (nowa >= a) {
          break;
        }
      }
      if (nowa >= a) {
        break;
      }
    }
  }

  int nowb = 1;
  while (nowb < b) {
    for (int i = 51; i < 100; i += 2) {
      for (int j = 1; j < 100; j += 2) {
        ans[i][j] = true;
        nowb++;
        if (nowb >= b) {
          break;
        }
      }
      if (nowb >= b) {
        break;
      }
    }
  }

  cout << 100 << " " << 100 << endl;
  rep(i, 100) {
    rep(j, 100) cout << (ans[i][j] ? '#' : '.');
    cout << endl;
  }
  return 0;
}