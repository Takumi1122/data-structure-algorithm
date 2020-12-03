#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n - 1);
  rep(i, n - 1) cin >> a[i];

  int sum = 0;
  rep(i, n - 1) sum += a[i];
  int ans = n * m - sum;

  if (ans > k) {
    cout << -1 << endl;
  } else {
    cout << max(ans, 0) << endl;
  }
  return 0;
}