#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  bool ok = false;
  int cnt = 0;
  rep(i, n) {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2) {
      cnt++;
    } else {
      cnt = 0;
    }
    if (cnt >= 3) ok = true;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}