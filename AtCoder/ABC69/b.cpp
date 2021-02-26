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
  ans += s[0];
  ans += to_string(s.size() - 2);
  ans += s[s.size() - 1];
  cout << ans << endl;
  return 0;
}