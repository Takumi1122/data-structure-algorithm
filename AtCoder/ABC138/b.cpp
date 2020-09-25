#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  double sum = 0;
  rep(i, n) {
    double an;
    cin >> an;
    double s = 1 / an;
    sum += s;
  }
  double ans = 1 / sum;
  cout << std::fixed << std::setprecision(10) << ans << endl;
  return 0;
}