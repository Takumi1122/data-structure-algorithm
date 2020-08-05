#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double n;
  cin >> n;
  int n1 = (n + 1) / 2;
  double ans = n1 / n;
  printf("%.10f\n", ans);
  return 0;
}