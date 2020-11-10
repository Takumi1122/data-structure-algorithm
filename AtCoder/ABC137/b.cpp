#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k, x;
  cin >> k >> x;
  int mn = x - k + 1;
  int mx = x + k - 1;
  for (int i = mn; i <= mx; i++) {
    cout << i << endl;
  }
  return 0;
}