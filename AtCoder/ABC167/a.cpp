#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s, t;
  cin >> s >> t;
  bool ok = true;
  rep(i, s.size()) {
    if (s[i] != t[i]) ok = false;
  }
  if (s.size() + 1 != t.size()) {
    ok = false;
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}