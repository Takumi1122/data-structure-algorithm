#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const double PI = acosl(-1.0);

int main() {
  int r;
  cin >> r;
  double ans = 2 * PI * r;
  printf("%.15f\n", ans);
  return 0;
}