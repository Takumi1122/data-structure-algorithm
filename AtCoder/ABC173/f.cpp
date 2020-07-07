#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連結成分数 = 頂点数 - 辺数

int main() {
  int n;
  cin >> n;
  ll V = 0, E = 0;
  for (int i = 1; i <= n; ++i) V += ll(i) * (n - i + 1);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    E += ll(a) * (n - b + 1);
  }
  ll ans = V - E;
  cout << ans << endl;
  return 0;
}
