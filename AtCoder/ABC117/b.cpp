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

  int mx = 0;
  int sum = 0;
  rep(i, n) {
    mx = max(mx, l[i]);
    sum += l[i];
  }
  sum -= mx;

  if (mx < sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}