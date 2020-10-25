#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 区間スケジューリング問題の応用

void solve(ll n, ll m) {
  if (m == 0) {
    ll cur = 1;
    rep(i, n) cout << cur++ << " " << cur++ << endl;
    return;
  }

  if (m < 0 || m >= n - 1) {
    cout << -1 << endl;
    return;
  }

  const ll GETA = 500000000;
  cout << 1 << " " << GETA << endl;
  ll cur = 2;
  rep(i, m + 1) cout << cur++ << " " << cur++ << endl;
  cur = GETA + 1;
  rep(i, n - m - 2) cout << cur++ << " " << cur++ << endl;
}

int main() {
  ll n, m;
  cin >> n >> m;
  solve(n, m);
}