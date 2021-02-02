#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<ll> cnt(5, 0);
  rep(i, n) {
    string s;
    cin >> s;
    if (s[0] == 'M') cnt[0]++;
    if (s[0] == 'A') cnt[1]++;
    if (s[0] == 'R') cnt[2]++;
    if (s[0] == 'C') cnt[3]++;
    if (s[0] == 'H') cnt[4]++;
  }

  ll ans = 0;
  for (int bit = 0; bit < (1 << 5); bit++) {
    if (__builtin_popcount(bit) != 3) continue;
    ll sum = 1;
    rep(i, 5) {
      if (bit & (1 << i)) sum *= cnt[i];
    }
    ans += sum;
  }

  cout << ans << endl;
  return 0;
}