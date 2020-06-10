#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }
  int c = 0, num = 1;
  bool ok = false;
  rep(i, n) {
    if (a[i] == num) {
      num++;
      ok = true;
    } else {
      c++;
    }
  }
  if (ok) {
    cout << c << endl;
  } else {
    cout << -1 << endl;
  }
}