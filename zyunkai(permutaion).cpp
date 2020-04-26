#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 100000000;  // 十分大きな値

int main() {
  // 入力
  int n;  // 都市数
  cin >> n;
  vector<vector<int> > dist(n, vector<int>(n));  // 各都市間の所要時間
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> dist[i][j];
    }
  }

  // 初期順列
  vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;

  // 探索
  int res = INF;
  do {
    /* 順序 order についての所要時間を計算 */
    int temp_dist = 0;
    for (int i = 1; i < n; ++i) {
      temp_dist += dist[order[i - 1]][order[i]];
    }
    /* 暫定値より小さかったら更新 */
    if (temp_dist < res) {
      res = temp_dist;
    }
  } while (next_permutation(order.begin(), order.end()));

  // 答えを出力
  cout << res << endl;
}
