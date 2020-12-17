#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int cnt = 0;
      for (int k = i; k <= j; k++) {
        if (s[k] == 'A' || s[k] == 'C' || s[k] == 'G' || s[k] == 'T') {
          cnt++;
          ans = max(ans, cnt);
        } else {
          cnt = 0;
        }
      }
    }
  }

  cout << ans << endl;
  return 0;
}