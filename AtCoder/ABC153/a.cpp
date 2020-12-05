#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int h, a;
  cin >> h >> a;
  int ans = (h + a - 1) / a;
  cout << ans << endl;
  return 0;
}