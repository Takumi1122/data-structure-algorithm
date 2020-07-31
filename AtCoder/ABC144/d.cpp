#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = acos(-1);

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double tn;
  double ans;
  if (a * a * b > 2 * x) {
    tn = (a * b * b) / (2 * x);
    ans = atan(tn);
  } else {
    tn = 2 * (a * a * b - x) / (a * a * a);
    ans = atan(tn);
  }
  cout << std::fixed << std::setprecision(10) << ans * double(180) / PI << endl;
  return 0;
}