#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;
  int s = a - 1;
  int t = b - 1;
  // 切り上げ
  int ans = (t + s - 1) / s;
  cout << ans << endl;
  return 0;
}
