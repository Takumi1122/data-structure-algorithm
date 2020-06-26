#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 入力
int n;
vector<vector<P>> v;

// 整数 bit に対応する「決め打ち」が整合しているかを判定
bool judge(int bit) {
  // i 人目の証言を検証する
  rep(i, n) {
    // i 人目が「不親切」だったら、証言はすべて無意味
    if (!(bit & (1 << i))) continue;

    // それぞれ確認
    for (P xy : v[i]) {
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
  cin >> n;
  v.resize(n);

  rep(i, n) {
    int a;
    cin >> a;
    v[i].resize(a);
    rep(j, a) {
      cin >> v[i][j].first >> v[i][j].second;
      --v[i][j].first;  // 0-indexed に
    }
  }

  int res = 0;
  for (int bit = 0; bit < (1 << n); ++bit) {
    // 矛盾 check
    if (judge(bit)) {
      // bit に含まれる人数を数える
      int count = 0;
      rep(i, n) {
        if (bit & (1 << i)) ++count;
      }
      res = max(res, count);
    }
  }

  cout << res << endl;
}