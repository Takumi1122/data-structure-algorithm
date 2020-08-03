#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(l.begin(), l.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = l[i];
      int b = l[j];
      auto ite1 = upper_bound(l.begin() + j, l.end(), abs(a - b));
      int id1 = distance(l.begin(), ite1);
      auto ite2 = lower_bound(l.begin() + j, l.end(), a + b);
      int id2 = distance(l.begin(), ite2);
      int num = id2 - id1 - 1;
      ans += num;
    }
  }

  cout << ans << endl;
  return 0;
}