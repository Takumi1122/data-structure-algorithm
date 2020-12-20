#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool ei(int n) {
  while (n) {
    if (n % 8 == 7) return true;
    n /= 8;
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    string s = to_string(i);
    bool ok = true;
    rep(j, s.size()) {
      if (s[j] == '7') ok = false;
    }
    if (ei(i)) ok = false;
    if (ok) ans++;
  }
  cout << ans << endl;
  return 0;
}