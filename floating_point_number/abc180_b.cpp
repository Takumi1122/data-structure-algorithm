#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n);
  rep(i, n) cin >> x[i];

  ll man = 0;
  double yu = 0;
  ll ch = 0;

  rep(i, n) {
    man += abs(x[i]);
    yu += abs(x[i]) * abs(x[i]);
    ch = max(ch, abs(x[i]));
  }

  yu = sqrt(yu);

  cout << man << endl;
  printf("%.15f\n", yu);
  cout << ch << endl;
  return 0;
}