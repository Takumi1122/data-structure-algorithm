#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int k;
  cin >> k;
  string s = "ACL";
  string ans;
  rep(i, k) ans += s;
  cout << ans << endl;
  return 0;
}