#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 平均最大化
// 蟻本P132 : 平均最大化

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> w(n), v(n);
  rep(i, n) cin >> w[i] >> v[i];

  vector<double> y(n);
  // 単位重さあたりの価値がx以上となるように選ぶことができるかどうか
  auto f = [&](double x) {
    rep(i, n) y[i] = v[i] - x * w[i];
    sort(y.begin(), y.end(), greater<double>());
    double sum = 0;
    rep(i, k) sum += y[i];

    return sum >= 0;
  };

  double l = 0;
  double r = 1e12;
  rep(i, 100) {
    double c = (l + r) / 2;
    if (f(c))
      l = c;
    else
      r = c;
  }

  printf("%.2f\n", r);
}