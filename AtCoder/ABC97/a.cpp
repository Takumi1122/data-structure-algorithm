#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(a - c) <= d) {
    cout << "Yes" << endl;
    return 0;
  }
  if (abs(a - b) <= d && abs(b - c) <= d) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}