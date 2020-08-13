#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  rep(i, s.size()) {
    if ((i + 1) % 2 == 0) {
      if (s[i] != 'L' && s[i] != 'U' && s[i] != 'D') ok = false;
    } else {
      if (s[i] != 'R' && s[i] != 'U' && s[i] != 'D') ok = false;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}