#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// すべてのマスを左上から見ていき、「おかない」「縦に置く」「横に置く」の3択を選択していく
// DFSによる全探索

/*
    参考リンク
    ABC 196 D - Hanjo
      https://atcoder.jp/contests/abc196/tasks/abc196_d
*/

int h, w, a, b;
bool used[16][16];

int dfs(int i, int j, int a) {
  // 最後まで探索して、長方形のタイルを使い切っているなら、組合せを+1する
  if (i == h) return a == 0;
  // 横の端まで行ったら次の行へ
  if (j == w) return dfs(i + 1, 0, a);
  // 既に置かれているなら何もできないので、次のマスへ
  if (used[i][j]) return dfs(i, j + 1, a);

  int res = 0;

  // 縦置き
  if (i + 1 < h && !used[i + 1][j] && 0 < a) {
    used[i][j] = used[i + 1][j] = true;
    res += dfs(i, j + 1, a - 1);
    used[i][j] = used[i + 1][j] = false;
  }
  // 横置き
  if (j + 1 < w && !used[i][j + 1] && 0 < a) {
    used[i][j] = used[i][j + 1] = true;
    res += dfs(i, j + 1, a - 1);
    used[i][j] = used[i][j + 1] = false;
  }
  // 何も置かない
  res += dfs(i, j + 1, a);

  return res;
}

int main() {
  cin >> h >> w >> a >> b;
  cout << dfs(0, 0, a) << endl;
}