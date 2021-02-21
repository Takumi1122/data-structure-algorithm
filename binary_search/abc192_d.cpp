#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 192 D - Base n
      https://atcoder.jp/contests/abc192/tasks/abc192_d
*/

int main() {
  string x;
  cin >> x;
  ll m;
  cin >> m;

  // 1桁の場合
  if (x.size() == 1) {
    if (stoi(x) <= m)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }

  // 2桁以上の場合
  int d = 0;
  for (char c : x) d = max(d, int(c - '0'));
  ll ac = d, wa = m + 1;
  while (wa - ac > 1) {
    // wj: waiting judge
    // wj進数
    ll wj = (ac + wa) / 2;
    // v: 10進数に変換
    ll v = 0;
    for (char c : x) {
      if (v > m / wj)
        // オーバーフロー対策
        v = m + 1;
      else
        v = v * wj + (c - '0');
    }
    if (v <= m)
      ac = wj;
    else
      wa = wj;
  }
  cout << ac - d << endl;
  return 0;
}