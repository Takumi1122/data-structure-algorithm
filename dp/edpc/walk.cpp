#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest R - Walk
      https://atcoder.jp/contests/dp/tasks/dp_r
*/

using matrix = vector<vector<ll>>;
const int mod = 1000000007;

int n;
ll K;
matrix A;

// 行列の掛け算
matrix mul(matrix &a, matrix &b) {
  matrix res(n, vector<ll>(n, 0));
  rep(i, n) rep(j, n) rep(k, n)(res[i][j] += a[i][k] * b[k][j]) %= mod;
  return res;
}

// 行列累乗
matrix pow(matrix m, ll k) {
  matrix res(n, vector<ll>(n, 0));
  rep(i, n) res[i][i] = 1;  // 単位行列にする

  while (k > 0) {
    if (k & 1) res = mul(res, m);
    m = mul(m, m);
    k >>= 1;
  }
  return res;
}

int main() {
  cin >> n >> K;
  A.assign(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];

  A = pow(A, K);

  ll ans = 0;
  rep(i, n) rep(j, n) {
    ans += A[i][j];
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}