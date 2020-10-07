#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 最小値の最大化
// 蟻本P131 : Aggressive cows

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  sort(x.begin(), x.end());

  // 任意の牛の間の間隔をd以上とすることができるか
  auto f = [&](int d) {
    int last = 0;
    for (int i = 1; i < m; i++) {
      int crt = last + 1;
      while (crt < n && x[crt] - x[last] < d) {
        crt++;
      }
      if (crt == n) return false;
      last = crt;
    }
    return true;
  };

  int l = 0;
  int r = 1e9 + 1;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;
}