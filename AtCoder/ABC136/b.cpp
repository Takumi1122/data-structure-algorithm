#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

bool f(int x) {
  int keta = 0;
  while (x) {
    keta++;
    x /= 10;
  }
  return (keta % 2 == 1);
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (f(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}