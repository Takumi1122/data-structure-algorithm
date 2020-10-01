#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    AtCoder Beginner Contest 141 E - Who Says a Pun?
      https://atcoder.jp/contests/abc141/tasks/abc141_e
*/

// ローリングハッシュ
// 構築 O(n)
// get O(1)
// getLCP O(log(n))
struct RollingHash {
  static const int base1 = 1007, base2 = 2009;
  static const int mod1 = 1000000007, mod2 = 1000000009;
  vector<ll> hash1, hash2, power1, power2;

  // construct
  RollingHash(const string &S) {
    int n = (int)S.size();
    // hash[i]: １文字目からi文字目までのハッシュ値
    hash1.assign(n + 1, 0);
    hash2.assign(n + 1, 0);
    // power[i]: base^i
    power1.assign(n + 1, 1);
    power2.assign(n + 1, 1);
    for (int i = 0; i < n; ++i) {
      hash1[i + 1] = (hash1[i] * base1 + S[i]) % mod1;
      hash2[i + 1] = (hash2[i] * base2 + S[i]) % mod2;
      power1[i + 1] = (power1[i] * base1) % mod1;
      power2[i + 1] = (power2[i] * base2) % mod2;
    }
  }

  // get hash of S[left:right]
  // ex: get(0, 7) -> 先頭から7文字までのハッシュ値 S[0]〜S[6]
  // ex: get(1, 7) -> 2文字目から7文字目までのハッシュ値 S[1]〜S[6]
  inline pair<ll, ll> get(int l, int r) const {
    ll res1 = hash1[r] - hash1[l] * power1[r - l] % mod1;
    if (res1 < 0) res1 += mod1;
    ll res2 = hash2[r] - hash2[l] * power2[r - l] % mod2;
    if (res2 < 0) res2 += mod2;
    return {res1, res2};
  }

  // get lcp of S[a:] and T[b:]
  // 最長共通接頭辞の長さ
  inline int getLCP(int a, int b) const {
    int len = min((int)hash1.size() - a, (int)hash1.size() - b);
    int low = 0, high = len;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (get(a, a + mid) != get(b, b + mid))
        high = mid;
      else
        low = mid;
    }
    return low;
  }
};

int main() {
  int n;
  string S;
  cin >> n >> S;

  // ロリハ
  RollingHash rh(S);

  // 求める
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int lcp = rh.getLCP(i, j);
      lcp = min(lcp, j - i);
      res = max(res, lcp);
    }
  }

  cout << res << endl;
}