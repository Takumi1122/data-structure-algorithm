#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/* next combination */
int next_combination(int sub) {
  int x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}

int main() {
  int n = 5;  // {0, 1, 2, 3, 4} の部分集合を考える
  int k = 3;

  int bit = (1 << k) - 1;  // bit = {0, 1, 2}
  for (; bit < (1 << n); bit = next_combination(bit)) {
    /* ここに処理を書く */

    /* きちんとできていることを確認してみる */
    // bit の表す集合を求める
    vector<int> s;
    rep(i, n) {
      if (bit & (1 << i)) {  // i が bit に入るかどうか
        s.push_back(i);
      }
    }

    // bit の表す集合の出力
    cout << bit << ": {";
    rep(i, s.size()) { cout << s[i] << " "; }
    cout << "}" << endl;
  }
}