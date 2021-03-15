#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int mn = 0;
  int mx = 0;
  for (int i = 1; i <= 10000000; i++) {
    if (w <= b * i) {
      mn = i;
      break;
    }
  }
  for (int i = 1; i <= 10000000; i++) {
    if (w < a * i) {
      mx = i - 1;
      break;
    }
  }
  if (mn > mx) {
    cout << "UNSATISFIABLE" << endl;
    return 0;
  }
  cout << mn << " " << mx << endl;
  return 0;
}