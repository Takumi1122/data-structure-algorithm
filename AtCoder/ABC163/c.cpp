#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n - 1; i++) cin >> a[i];
  vector<int> c(n);

  for (int i = 0; i < n - 1; i++) {
    c[a[i] - 1]++;
  }

  rep(i, n) { printf("%d\n", c[i]); }

  return 0;
}