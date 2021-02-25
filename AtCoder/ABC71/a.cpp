#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int x, a, b;
  cin >> x >> a >> b;
  if (abs(x - a) < abs(x - b)) {
    cout << 'A' << endl;
  } else {
    cout << 'B' << endl;
  }
  return 0;
}