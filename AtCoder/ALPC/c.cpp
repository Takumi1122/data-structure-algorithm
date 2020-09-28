#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/all>
using namespace atcoder;

int main() {
  int t;
  cin >> t;
  rep(i, t) {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << floor_sum(n, m, a, b) << endl;
  }
}