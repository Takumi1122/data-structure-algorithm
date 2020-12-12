#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 171 E - Red Scarf
      https://atcoder.jp/contests/abc171/tasks/abc171_e
*/

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll b = 0;
  rep(i, n) {
    cin >> a[i];
    b ^= a[i];
  }

  rep(i, n) cout << (b ^ a[i]) << endl;
  return 0;
}