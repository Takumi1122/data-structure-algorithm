#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// ダブリングは、全体の要素数がN個あって1回移動した時にどの要素に到達するのか定まっているとき、
//「K個先の要素を求めるのに𝑂(𝐾) かかる」ような状況において
// ・前処理：𝑂(𝑁log𝐾)時間, 𝑂(𝑁log𝐾) 空間
// ・クエリ：𝑂(log𝐾)
// で行うことができるようにするアルゴリズムです。

int main() {
  ll n, K;
  cin >> n >> K;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;  // 0-indexed に変更
  }

  int logK = 1;
  while ((1LL << logK) < K) logK++;
  // doubling[k][i] : i番目から 2^k 進んだ町
  vector<vector<int> > doubling(logK, vector<int>(n));
  rep(i, n) { doubling[0][i] = a[i]; }
  // 前処理 doubling の計算
  rep(k, logK - 1) {
    rep(i, n) doubling[k + 1][i] = doubling[k][doubling[k][i]];
  }

  int now = 0;
  for (int k = 0; K > 0; k++) {
    if (K & 1) now = doubling[k][now];
    K = K >> 1;
  }
  cout << now + 1 << endl;
}