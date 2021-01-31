#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, s, d;
  cin >> n >> s >> d;
  bool ok = false;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    if (x < s && y > d) {
      ok = true;
    }
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}