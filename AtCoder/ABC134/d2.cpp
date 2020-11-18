#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> b(n);
  for (int i = n; i >= 1; i--) {
    int sum = 0;
    for (int j = i * 2; j <= n; j += i) sum += b[j - 1];
    if (sum % 2 == a[i - 1]) {
      b[i - 1] = 0;
    } else {
      b[i - 1] = 1;
    }
  }

  int m = 0;
  rep(i, n) {
    if (b[i]) m++;
  }
  cout << m << endl;
  rep(i, n) {
    if (b[i]) cout << i + 1 << endl;
  }
  return 0;
}