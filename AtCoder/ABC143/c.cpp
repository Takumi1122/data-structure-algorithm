#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<char> c(n);
  rep(i, n) c[i] = s[i];

  ll ans = 0;
  rep(i, n - 1) {
    if (c[i] != c[i + 1]) {
      ans++;
    }
  }

  cout << ans + 1 << endl;
  return 0;
}