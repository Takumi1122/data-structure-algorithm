#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  sort(h.begin(), h.end());
  ll c = 0;
  if (n <= k) {
    cout << 0 << endl;
  } else {
    rep(i, n - k) c += h[i];
    cout << c << endl;
  }
  return 0;
}