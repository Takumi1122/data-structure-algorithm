#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x;
  cin >> x;
  int c500 = x / 500;
  x -= c500 * 500;
  int c5 = x / 5;
  int ans = c500 * 1000 + c5 * 5;
  cout << ans << endl;
  return 0;
}