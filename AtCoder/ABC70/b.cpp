#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ac = max(a, c);
  int bd = min(b, d);
  if (ac <= bd) {
    cout << bd - ac << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}