#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 解を仮定し可能か判定
// 蟻本P129 : Cable master
// 小数値が解の場合、二分探索を100回程度繰り返す

int main() {
  int n, k;
  cin >> n >> k;
  vector<double> L(n);
  rep(i, n) cin >> L[i];

  // 長さxの紐をk本切り出すことができるか
  auto f = [&](double x) {
    int num = 0;
    rep(i, n) num += (int)(L[i] / x);
    return num >= k;
  };

  double l = 0;
  double r = 1e7;
  rep(i, 100) {
    double c = (l + r) / 2;
    if (f(c))
      l = c;
    else
      r = c;
  }

  cout << (int)r << endl;
}