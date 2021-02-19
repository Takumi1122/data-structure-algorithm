#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (b == c) {
    cout << a << endl;
  } else if (a == c) {
    cout << b << endl;
  } else {
    cout << c << endl;
  }
  return 0;
}