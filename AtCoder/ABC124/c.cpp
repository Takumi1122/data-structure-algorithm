#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  string s1, s2;
  rep(i, n) {
    if (i % 2 == 0) {
      s1 += '1';
      s2 += '0';
    } else {
      s2 += '1';
      s1 += '0';
    }
  }

  int cnt1 = 0, cnt2 = 0;
  int ans = n + 1;
  rep(i, n) {
    if (s[i] != s1[i]) cnt1++;
    if (s[i] != s2[i]) cnt2++;
  }
  ans = min(cnt1, cnt2);

  cout << ans << endl;
  return 0;
}