#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, l;
  cin >> n >> l;
  int sum = 0;
  rep(i, n) sum += (l + i);
  int ans;
  int ab = 1e9;
  rep(i, n) {
    int a = sum - (l + i);
    if (ab > abs(sum - a)) {
      ab = abs(sum - a);
      ans = a;
    }
  }
  cout << ans << endl;
  return 0;
}