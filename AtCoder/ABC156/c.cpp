#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];
  int mn = (1e8);
  for (int i = 1; i <= 600; ++i) {
    int sum = 0;
    rep(j, n) sum += (x[j] - i) * (x[j] - i);
    mn = min(mn, sum);
  }
  cout << mn << endl;
  return 0;
}