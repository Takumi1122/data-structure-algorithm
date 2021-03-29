#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 素因数分解したときの偶数(2)に注目
// 素数は2以外は全て奇数
// 2が0個 (n % 4 == 1 || n % 4 == 3) なら奇数が多い
// 2が1個 (n % 4 == 2) なら偶数と奇数が同じ数
// 2が2個以上 (n % 4 == 0) なら偶数が多い

/*
    参考リンク
    ARC 116 A - Odd vs Even
      https://atcoder.jp/contests/arc116/tasks/arc116_a
*/

int main() {
  int T;
  cin >> T;
  rep(ti, T) {
    ll n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 3) {
      cout << "Odd" << endl;
    } else if (n % 4 == 2) {
      cout << "Same" << endl;
    } else {
      cout << "Even" << endl;
    }
  }
  return 0;
}