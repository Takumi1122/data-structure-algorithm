#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 不偏ゲーム

/*
    // Grundy数の定義
    ・終了状態PfでのGrundy数 = 0
    ・ある状態PでのGrundy数 = mex(「Pから到達可能な状態P’のGrundy数」の集合 )

    ・Grundy数が正: 上手く手を選ぶと次の状態でのGrundy数を0にできる→先手必勝
    ・Grundy数が0: どのように手を選んでも、次のGrundy数はnon-zero→後手必勝
*/

/*
    参考リンク
    yukicoder No.2 素因数ゲーム
      https://yukicoder.me/problems/18
*/

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