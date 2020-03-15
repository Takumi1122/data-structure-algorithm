#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 10;
  int A = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7);  // {A = {2, 3, 5, 7}

  for (int bit = A;; bit = (bit - 1) & A) {
    /* ここに処理を書く */

    /* きちんとできていることを確認してみる */
    // bit の表す集合を求める
    vector<int> S;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {  // i が bit に入るかどうか
        S.push_back(i);
      }
    }

    // bit の表す集合の出力
    cout << bit << ": {";
    for (int i = 0; i < (int)S.size(); ++i) {
      cout << S[i] << " ";
    }
    cout << "}" << endl;

    // 最後の 0 で break
    if (!bit) break;
  }
}