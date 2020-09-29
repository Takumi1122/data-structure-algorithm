#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  string s;
  cin >> s;
  vector<int> sa = suffix_array(s);
  ll answer = 1LL * s.size() * (s.size() + 1) / 2;
  for (auto x : lcp_array(s, sa)) {
    answer -= x;
  }
  cout << answer << endl;
  return 0;
}
