#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll solve(ll n) {
  if (n % 2 == 1) return 0;

  ll res = 0;
  n /= 2;
  while (n) {
    res += n / 5;
    n /= 5;
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  cout << solve(n) << endl;
}