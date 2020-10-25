#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  ll a = 0;
  ll b = 0;

  for (int i = 1; i <= 38; i++) {
    ll th = 1;
    ll sub = i;
    while (sub) {
      sub--;
      th *= 3;
    }
    if (th >= n) break;
    ll fi = n - th;
    if (fi <= 0) break;
    ll cnt = 0;
    while (fi % 5 == 0) {
      fi = fi / 5;
      cnt++;
    }

    if (fi == 1 && cnt >= 1) {
      b = cnt;
      a = i;
      break;
    }
  }

  if (a == 0 || b == 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << a << " " << b << endl;
  return 0;
}