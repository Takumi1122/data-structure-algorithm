#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = n - a + b;
  cout << ans << endl;
  return 0;
}