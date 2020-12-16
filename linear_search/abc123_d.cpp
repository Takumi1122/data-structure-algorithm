#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 123 D - Cake 123
      https://atcoder.jp/contests/abc123/tasks/abc123_d
*/

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];

  // A + B の上位K個
  vector<ll> ab;
  rep(i, x) rep(j, y) ab.push_back(a[i] + b[j]);
  sort(ab.begin(), ab.end(), greater<ll>());
  ab.resize(k);

  // AB と C
  vector<ll> abc;
  rep(i, ab.size()) rep(j, z) abc.push_back(ab[i] + c[j]);
  sort(abc.begin(), abc.end(), greater<ll>());

  // 出力
  rep(i, k) cout << abc[i] << endl;
  return 0;
}