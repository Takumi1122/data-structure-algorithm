#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 偶奇性

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mx = max({a, b, c});
  int sum = abs(mx - a) + abs(mx - b) + abs(mx - c);
  if (sum % 2 == 0) {
    cout << sum / 2 << endl;
  } else {
    cout << ((sum + 1) / 2) + 1 << endl;
  }
  return 0;
}