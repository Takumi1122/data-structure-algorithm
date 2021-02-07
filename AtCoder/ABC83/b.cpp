#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

ll digsum(ll n) {
  ll res = 0;
  while (n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (a <= digsum(i) && digsum(i) <= b) sum += i;
  }

  cout << sum << endl;
  return 0;
}