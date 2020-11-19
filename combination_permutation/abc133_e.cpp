#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 木DP

/*
    参考リンク
    ABC 133 E - Virus Tree 2
      https://atcoder.jp/contests/abc133/tasks/abc133_e
*/

const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x = 0) : x(x % mod) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};

struct combination {
  vector<mint> fact, ifact;
  combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n - k];
  }
};

int k;
mint ans;
vector<int> G[100005];
combination comb(100005);

mint f(int n, int k) {
  if (n < 0) return 0;
  // nPk = nCk * k!
  mint res = comb(n, k);
  res *= comb.fact[k];
  return res;
}

void dfs(int v, int p = -1) {
  int nk = (p == -1) ? k - 1 : k - 2;
  int c = (p == -1) ? G[v].size() : G[v].size() - 1;
  ans *= f(nk, c);
  for (int u : G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int main() {
  int n;
  cin >> n >> k;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ans = 1;
  dfs(0);
  ans *= k;
  cout << ans.x << endl;
  return 0;
}