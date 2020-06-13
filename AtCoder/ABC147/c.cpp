#include <iostream>
#include <vector>
using namespace std;

// 1 つの証言を表す構造体
using pint = pair<int, int>;  // 「人」と「0 or 1」

// 入力
int N;
vector<vector<pint>> v;

// 整数 bit に対応する「決め打ち」が整合しているかを判定
bool judge(int bit) {
  // i 人目の証言を検証する
  for (int i = 0; i < N; ++i) {
    // i 人目が「不親切」だったら、証言はすべて無意味
    if (!(bit & (1 << i))) continue;

    // それぞれ確認
    for (pint xy : v[i]) {
      int x = xy.first;   // x が
      int y = xy.second;  // y = 1: 正直、y = 0: 不親切

      // y = 1 なのに「不親切」だったらダメ
      if (y == 1 && !(bit & (1 << x))) return false;

      // y = 0 なのに「正直者」だったらダメ
      if (y == 0 && (bit & (1 << x))) return false;
    }
  }
  return true;
}

int main() {
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; ++i) {
    int A;
    cin >> A;
    v[i].resize(A);
    for (int j = 0; j < A; ++j) {
      cin >> v[i][j].first >> v[i][j].second;
      --v[i][j].first;  // 0-indexed に
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << N); ++bit) {
    // 矛盾 check
    if (judge(bit)) {
      // bit に含まれる人数を数える
      int count = 0;
      for (int i = 0; i < N; ++i) {
        if (bit & (1 << i)) ++count;
      }
      res = max(res, count);
    }
  }

  cout << res << endl;
}