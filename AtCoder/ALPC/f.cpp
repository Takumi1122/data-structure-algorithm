#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];

  vector<ll> c = convolution(a, b);
  // or: vector<long long> c = convolution<998244353>(a, b);

  rep(i, n + m - 1) cout << c[i] << endl;
  return 0;
}