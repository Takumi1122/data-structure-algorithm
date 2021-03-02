#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;

  bool ok = false;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int a = i * 1.08;
    if (a == n) {
      ans = i;
      ok = true;
      break;
    }
  }

  if (ok) {
    cout << ans << endl;
  } else {
    cout << ":(" << endl;
  }
}