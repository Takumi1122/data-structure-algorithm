#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int pre = -999;
  rep(i, n) {
    if (pre <= a[i] - 1) {
      pre = a[i] - 1;
    } else if (pre <= a[i]) {
      pre = a[i];
    } else {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}