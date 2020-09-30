#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;

  if (b < c || d < a) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}