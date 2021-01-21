#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 余りと和
// すべてが「5で割って1余る」数であれば,ここから5個の整数を選んだ時にこれらの合計は必ず5で割り切れる

/*
    参考リンク
    ABC 96 D - Five, Five Everywhere
      https://atcoder.jp/contests/abc096/tasks/abc096_d
*/

// 素数判定 O(√n)
bool is_prime(ll n) {
  if (n == 1) return false;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  cin >> n;
  vector<int> pr;
  for (int i = 2; i <= 55555; i++) {
    if (is_prime(i) && i % 5 == 1) pr.push_back(i);
  }

  rep(i, n) cout << pr[i] << endl;
  return 0;
}