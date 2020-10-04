#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> dp(4);
    for (int j = i; j < n; j++) {
      int c;
      if (s[j] == 'A') c = 0;
      if (s[j] == 'G') c = 1;
      if (s[j] == 'T') c = 2;
      if (s[j] == 'C') c = 3;
      dp[c]++;
      if ((j - i + 1) % 2 == 1) continue;
      if (dp[0] == dp[2] && dp[1] == dp[3]) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}