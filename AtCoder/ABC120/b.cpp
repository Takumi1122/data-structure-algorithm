#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  int cnt = 0;
  for (int i = min(a, b); i >= 1; i--) {
    if (a % i == 0 && b % i == 0) cnt++;
    if (cnt == k) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}