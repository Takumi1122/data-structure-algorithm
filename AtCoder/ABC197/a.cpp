#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  string ans = s.substr(1);
  ans += s[0];
  cout << ans << endl;
  return 0;
}