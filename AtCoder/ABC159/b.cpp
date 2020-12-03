#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  rep(i, n) {
    if (s[i] != s[n - i - 1]) ok = false;
  }
  rep(i, (n - 1) / 2) {
    if (s[i] != s[(n - 1) / 2 - i - 1]) ok = false;
  }
  for (int i = (n + 2) / 2; i < n; i++) {
    if (s[i] != s[n - i - 1]) ok = false;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}