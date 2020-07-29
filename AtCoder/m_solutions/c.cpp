#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> mul(n + 1, 0);
  rep(i, n) mul[i + 1] = mul[i] + a[i];
  for (int i = k + 1; i <= n; i++) {
    ll mul1 = mul[i] - mul[i - k];
    ll mul2 = mul[i - 1] - mul[i - 1 - k];
    if (mul1 > mul2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}