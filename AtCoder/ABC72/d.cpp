#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  vector<int> cnt;
  for (int i = 1; i <= n;) {
    int c = 0;
    while (i <= n && p[i - 1] == i) {
      c++;
      i++;
    }
    i++;
    cnt.push_back(c);
  }

  int ans = 0;
  rep(i, cnt.size()) ans += (cnt[i] + 1) / 2;
  cout << ans << endl;
  return 0;
}