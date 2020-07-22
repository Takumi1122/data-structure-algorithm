#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<pair<ll, ll> > prime_factorize(ll n) {
  vector<pair<ll, ll> > res;
  for (ll a = 2; a * a <= n; ++a) {
    if (n % a != 0) continue;
    ll ex = 0;  // 指数

    // 割れる限り割り続ける
    while (n % a == 0) {
      ++ex;
      n /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (n != 1) res.push_back({n, 1});
  return res;
}

int main() {
  ll n;
  cin >> n;

  const auto &res = prime_factorize(n);
  // 肩の数を格納して Nim とみなす
  vector<int> nim;
  for (auto p : res) {
    int num = p.second;
    nim.push_back(num);
  }
  // XOR sum の計算
  int xor_sum = 0;
  for (auto t : nim) {
    xor_sum ^= t;
  }

  if (xor_sum == 0) {  // 後手必勝
    cout << "Bob" << endl;
  } else {  // 先手必勝
    cout << "Alice" << endl;
  }
  return 0;
}