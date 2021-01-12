#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> xp;
  vector<int> xm;
  rep(i, n) {
    int x;
    cin >> x;
    if (x < 0) {
      xm.push_back(-x);
    } else {
      xp.push_back(x);
    }
  }
  sort(xm.begin(), xm.end());
  int s1 = xp.size();
  int s2 = xm.size();

  ll ans = 1e9;
  for (int i = min(s1, k); i >= 1; i--) {
    ll sum;
    if (k - i - 1 >= 0) {
      if (k - i - 1 >= s2) break;
      sum = 2 * xp[i - 1] + xm[k - i - 1];
    } else {
      sum = xp[i - 1];
    }

    ans = min(ans, sum);
  }

  for (int i = min(s2, k); i >= 1; i--) {
    ll sum;
    if (k - i - 1 >= 0) {
      if (k - i - 1 >= s1) break;
      sum = 2 * xm[i - 1] + xp[k - i - 1];
    } else {
      sum = xm[i - 1];
    }

    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}