#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// n <= 10^7

int main() {
  int n;
  cin >> n;

  vector<ll> yaku(n + 1, 1);
  for (int i = 2; i <= n; i++) {
    yaku[i]++;
    for (ll j = i * 2; j <= n; j += i) {
      yaku[j]++;
    }
  }

  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i * yaku[i];
  }

  cout << sum << endl;
  return 0;
}