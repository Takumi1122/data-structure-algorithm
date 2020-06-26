#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;  // 仮想的な無限大の値

int main() {
  // 入力
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  // 累積和
  vector<ll> s(n + 1, 0);
  rep(i, n) s[i + 1] = s[i] + a[i];

  ll res = -INF;  // 最初は無限小の値に初期化しておく
  for (int i = 0; i <= n - k; ++i) {
    ll val = s[k + i] - s[i];
    if (res < val) res = val;
  }
  cout << res << endl;
}