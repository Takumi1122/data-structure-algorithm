#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool solve() {
  int n, m, t;
  cin >> n >> m >> t;
  vector<int> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];

  int now = 0;
  int bat = n;
  rep(i, m) {
    bat -= a[i] - now;
    now = a[i];
    if (bat <= 0) return false;

    bat += b[i] - a[i];
    if (bat > n) bat = n;
    now = b[i];
  }
  bat -= t - now;
  if (bat <= 0) return false;

  return true;
}

int main() {
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}