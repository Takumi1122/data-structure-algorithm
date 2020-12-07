#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> s(m);
  vector<int> c(m);
  rep(i, m) cin >> s[i] >> c[i];

  for (int i = 0; i <= 999; i++) {
    string s_sub = to_string(i);
    if (s_sub.size() != n) continue;
    int ok = true;
    rep(i, m) {
      if ((s_sub[s[i] - 1] - '0') != c[i]) ok = false;
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  return 0;
}