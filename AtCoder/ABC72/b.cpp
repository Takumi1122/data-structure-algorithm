#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  string ans = "";
  rep(i, s.size()) {
    if (i % 2 == 0) ans += s[i];
  }
  cout << ans << endl;
  return 0;
}