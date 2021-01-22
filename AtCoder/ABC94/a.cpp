#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  if (a > x) {
    cout << "NO" << endl;
    return 0;
  }
  if (a + b < x) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  return 0;
}