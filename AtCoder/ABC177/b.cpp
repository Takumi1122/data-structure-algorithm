#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  int n1 = s.size();
  int n2 = t.size();
  int ans = 10005;
  rep(i, n1 - n2 + 1) {
    string s1 = s.substr(i, n2);
    int cnt = 0;
    rep(j, n2) {
      if(t[j] != s1[j]) cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}