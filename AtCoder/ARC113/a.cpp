#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// AB <= K について Σ(K/i)よりK*log(K) (調和級数)

int main() {
  ll k;
  cin >> k;

  ll ans = 0;
  for (ll a = 1; a <= k; a++) {
    for (ll b = 1; b <= k; b++) {
      if (a * b > k) break;
      for (ll c = 1; c <= k; c++) {
        if (a * b * c > k) break;
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}