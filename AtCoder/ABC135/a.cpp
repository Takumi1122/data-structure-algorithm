#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b;
  cin >> a >> b;
  ll ab = a + b;
  if (ab % 2 == 0) {
    cout << ab / 2 << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}