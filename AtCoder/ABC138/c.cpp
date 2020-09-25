#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  priority_queue<double, vector<double>, greater<double>> v;
  rep(i, n) {
    double vn;
    cin >> vn;
    v.push(vn);
  }

  double ans = 0;
  rep(i, n - 1) {
    double v1 = v.top();
    v.pop();
    double v2 = v.top();
    v.pop();
    ans = (v1 + v2) / 2;
    v.push(ans);
  }
  cout << std::fixed << std::setprecision(10) << ans << endl;
  return 0;
}