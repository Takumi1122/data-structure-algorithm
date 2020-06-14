#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n = 5;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}