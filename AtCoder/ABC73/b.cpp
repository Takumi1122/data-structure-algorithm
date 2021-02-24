#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  rep(i, n) {
    int l, r;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}