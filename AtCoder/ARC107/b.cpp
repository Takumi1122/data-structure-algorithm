#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> com(2 * n + 1);
  if (k < 0) k = abs(k);

  for (int i = 2; i <= 2 * n; i++) {
    com[i] = min(i - 1, 2 * n - i + 1);
  }

  ll ans = 0;
  for (int i = k + 2; i <= 2 * n; i++) {
    ans += com[i] * com[i - k];
  }

  cout << ans << endl;
  return 0;
}