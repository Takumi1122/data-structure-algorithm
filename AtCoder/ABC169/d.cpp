#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;  // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  ll n;
  cin >> n;
  const auto &res = prime_factorize(n);
  int ans = 0;
  if (n == 1) {
    cout << 0 << endl;
  } else {
    for (auto p : res) {
      ll count = 0;
      ll sub = 1;
      ll n1 = p.second;
      while (n1 > 0) {
        n1 -= sub;
        if (n1 >= 0) {
          sub++;
          count++;
        }
      }
      ans += count;
    }
    cout << ans << endl;
  }
  return 0;
}