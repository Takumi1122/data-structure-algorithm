#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> m(n);
  rep(i, n) cin >> m[i];

  int sum = 0;
  int mn = 1e9;
  rep(i, n) {
    sum += m[i];
    mn = min(mn, m[i]);
  }

  cout << n + (x - sum) / mn << endl;
  return 0;
}