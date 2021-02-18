#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 1;
  while (n) {
    ans = min(ans + k, ans * 2);
    n--;
  }
  cout << ans << endl;
  return 0;
}