#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int k;
  cin >> k;
  if (k % 2 == 0) {
    int ans = (k / 2) * (k / 2);
    cout << ans << endl;
  } else {
    int ans = ((k + 1) / 2) * (k / 2);
    cout << ans << endl;
  }
  return 0;
}