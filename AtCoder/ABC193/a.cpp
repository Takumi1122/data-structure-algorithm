#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  double a, b;
  cin >> a >> b;
  double ans = 100.0 - (b * 100 / a);
  printf("%.10f\n", ans);
  return 0;
}