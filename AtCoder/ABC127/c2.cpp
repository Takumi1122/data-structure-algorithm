#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  int left = 1, right = n;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    left = max(left, a);
    right = min(right, b);
  }

  cout << max(right - left + 1, 0) << endl;
  return 0;
}