#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];
  int c = -1;
  int sum = 0;
  rep(i, m) sum += a[i];
  if (sum <= n) c = n - sum;
  cout << c << endl;
  return 0;
}