#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 計算量 : O(3^10)

/*
    参考リンク
    ABC 161 D - Lunlun Number
      https://atcoder.jp/contests/abc161/tasks/abc161_d
*/

void rec(int d, ll val, vector<ll> &all) {
  // 格納
  all.push_back(val);

  // 10 桁だったらそれ以上やらずに打ち切り
  if (d == 10) return;

  // 次の桁へ進む処理
  for (int j = -1; j <= 1; ++j) {
    int add = (val % 10) + j;
    if (add >= 0 && add <= 9) rec(d + 1, val * 10 + add, all);
  }
}

int main() {
  int k;
  cin >> k;
  vector<ll> all;
  for (int v = 1; v < 10; ++v) rec(1, v, all);

  // 小さい順に並び替える
  sort(all.begin(), all.end());

  // K 番目
  cout << all[k - 1] << endl;
}