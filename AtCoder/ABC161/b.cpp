#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int sum = 0;
  int cnt = 0;
  rep(i, n) { sum += a[i]; }
  rep(i, n) {
    if (4 * m * a[i] >= sum) {
      cnt++;
    }
  }

  if (cnt >= m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}