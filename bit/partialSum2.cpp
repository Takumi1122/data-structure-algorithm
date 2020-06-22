#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n = 10;
  int a = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7);  // a = {2, 3, 5, 7}

  for (int bit = a;; bit = (bit - 1) & a) {
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

    // 最後の 0 で break
    if (!bit) break;
  }
}