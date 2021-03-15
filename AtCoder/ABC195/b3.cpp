#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, w;
  cin >> a >> b >> w;

  int upper = w * 1000 / a;
  int lower = (w * 1000 + b - 1) / b;

  if (lower > upper) {
    cout << "UNSATISFIABLE" << endl;
  } else {
    cout << lower << " " << upper << endl;
  }
  return 0;
}