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
      int idr = lower_bound(l.begin(), l.end(), a + b) - l.begin();
      int idl = j + 1;
      int num = idr - idl;
      ans += num;
    }
  }

  cout << ans << endl;
  return 0;
}