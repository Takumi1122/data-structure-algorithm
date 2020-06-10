#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s, t;
  cin >> n;
  cin >> s >> t;
  string ans;
  rep(i, n) {
    ans += s[i];
    ans += t[i];
  }
  cout << ans << endl;
  return 0;
}