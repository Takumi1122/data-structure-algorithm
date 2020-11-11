#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<P> lr;
  lr.emplace_back(0, n - 1);
  rep(i, n - 1) {
    if (s[i] == 'L' && s[i + 1] == 'R') {
      lr[lr.size() - 1].second = i;
      lr.emplace_back(i + 1, n - 1);
    }
  }

  vector<int> ans(n, 0);
  rep(i, lr.size()) {
    for (int j = lr[i].first; j < lr[i].second; j++) {
      if (s[j] == 'R' && s[j + 1] == 'L') {
        ans[j + 1] += (lr[i].second - j + 1) / 2;
        ans[j + 1] += (j - lr[i].first + 1) / 2;
        ans[j] += (lr[i].second - j) / 2;
        ans[j] += (j - lr[i].first + 2) / 2;
      }
    }
  }

  rep(i, n) cout << ans[i] << endl;
  return 0;
}