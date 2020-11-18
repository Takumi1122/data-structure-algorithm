#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> s = a;
  sort(s.begin(), s.end(), greater<int>());

  rep(i, n) {
    int ans = s[0];
    if (s[0] == a[i]) ans = s[1];
    cout << ans << endl;
  }
  return 0;
}