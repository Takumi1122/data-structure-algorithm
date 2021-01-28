#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  vector<string> s(3);
  rep(i, 3) cin >> s[i];

  string ans = "";
  ans += s[0][0];
  ans += s[1][1];
  ans += s[2][2];

  cout << ans << endl;
  return 0;
}