#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ダブリング
// 全体の要素数がN個あって1回移動した時にどの要素に到達するのか定まっているとき、
//「K個先の要素を求めるのにO(K)かかる」ような状況において
// ・前処理 : O(Nlog(K))
// ・クエリ : O(log(K))
// で行うことができるようにするアルゴリズム

/*
    参考リンク
    ABC167 D - Teleporter
      https://atcoder.jp/contests/abc167/tasks/abc167_d
*/

int main() {
  ll n, K;
  cin >> n >> K;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }

  int logk = 1;
  while ((1LL << logk) < K) logk++;
  // doubling[k][i]: i番目から2^k進んだ町
  vector<vector<int> > doubling(logk, vector<int>(n));
  rep(i, n) doubling[0][i] = a[i];
  rep(k, logk - 1) {
    rep(i, n) doubling[k + 1][i] = doubling[k][doubling[k][i]];
  }

  int now = 0;
  for (int k = 0; K > 0; k++) {
    if (K & 1) now = doubling[k][now];
    K = K >> 1;
  }
  cout << now + 1 << endl;
  return 0;
}