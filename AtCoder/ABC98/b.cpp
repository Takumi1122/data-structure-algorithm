#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    string s1 = s.substr(0, i);
    string s2 = s.substr(i);
    int cnt = 0;
    set<char> st1;
    set<char> st2;
    rep(j, s1.size()) st1.insert(s1[j]);
    rep(j, s2.size()) st2.insert(s2[j]);
    for (auto c : st1) {
      if (st2.count(c)) cnt++;
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}