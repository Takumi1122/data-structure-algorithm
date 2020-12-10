#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  bool exist = false;
  rep(bit, 1 << n) {
    int sum = 0;
    rep(i, n) {
      if (bit & (1 << i)) {
        sum += a[i];
      }
    }
    if (sum == k) exist = true;
  }

  if (exist)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}