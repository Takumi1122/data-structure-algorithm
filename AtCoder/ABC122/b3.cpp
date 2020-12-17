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
  for (int i = 0; i < n; ++i) {
    int j;
    for (j = i; j < n; ++j) {
      if (s[j] != 'A' && s[j] != 'G' && s[j] != 'T' && s[j] != 'C') break;
    }
    ans = max(ans, j - i);
  }

  cout << ans << endl;
  return 0;
}