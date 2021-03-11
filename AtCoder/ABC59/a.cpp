#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  string ans = "";
  ans += toupper(s1[0]);
  ans += toupper(s2[0]);
  ans += toupper(s3[0]);
  cout << ans << endl;
  return 0;
}