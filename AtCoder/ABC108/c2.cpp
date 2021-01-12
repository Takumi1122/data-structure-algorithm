#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    a+b ≡ b+c ≡ c+a ≡ 0 (mod k)
    a+b ≡ b+c (mod k) <=> a ≡ c (mod k)
    対称性から a ≡ b ≡ c (mod k)

    また, a+b ≡ 0 (mod k) <=> 2a ≡ 0 (mod k)

    1: kが奇数の時
    kと2は互いに素なので, a ≡ 0 (mod k)
    a ≡ b ≡ c (mod k) より
    a ≡ b ≡ c ≡ 0 (mod k)

    2: kが偶数の時
    k = 2k'とすると
    a ≡ 0 (mod k) or a ≡ k' (mod k)
    a ≡ b ≡ c (mod k) より
    a ≡ b ≡ c ≡ 0 (mod k) or a ≡ b ≡ c ≡ k' (mod k)
*/

/*
    参考リンク
    ABC 108 C - Triangular Relationship
      https://atcoder.jp/contests/abc108/tasks/arc102_a
*/

int main() {
  ll n, k;
  cin >> n >> k;

  if (k % 2 == 0) {
    // a: n以下のkの倍数の個数
    ll a = n / k;
    // b: n以下のkで割ってk'あまる整数の個数
    ll b = (n + (k / 2)) / k;
    cout << a * a * a + b * b * b << endl;
  } else {
    // a: n以下のkの倍数の個数
    ll a = n / k;
    cout << a * a * a << endl;
  }
  return 0;
}