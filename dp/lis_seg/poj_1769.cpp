#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// データ構造を用いてのDP高速化 O(m * log(n))
// 蟻本P186: Minimizing maximizer

// 抽象化したセグメント木
template <class Monoid>
struct SegTree {
  using Func = function<Monoid(Monoid, Monoid)>;
  const Func F;
  const Monoid UNITY;
  int SIZE_R;
  vector<Monoid> dat;

  SegTree(int n, const Func f, const Monoid &unity) : F(f), UNITY(unity) {
    init(n);
  }
  void init(int n) {
    SIZE_R = 1;
    while (SIZE_R < n) SIZE_R *= 2;
    dat.assign(SIZE_R * 2, UNITY);
  }

  /* set, a is 0-indexed */
  void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
  void build() {
    for (int k = SIZE_R - 1; k > 0; --k) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
  }

  /* update a, a is 0-indexed */
  void update(int a, const Monoid &v) {
    int k = a + SIZE_R;
    dat[k] = v;
    while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
  }

  /* get [a, b), a and b are 0-indexed */
  Monoid get(int a, int b) {
    Monoid vleft = UNITY, vright = UNITY;
    for (int left = a + SIZE_R, right = b + SIZE_R; left < right;
         left >>= 1, right >>= 1) {
      if (left & 1) vleft = F(vleft, dat[left++]);
      if (right & 1) vright = F(dat[--right], vright);
    }
    return F(vleft, vright);
  }
  inline Monoid operator[](int a) { return dat[a + SIZE_R]; }

  /* debug */
  void print() {
    for (int i = 0; i < SIZE_R; ++i) {
      cout << (*this)[i];
      if (i != SIZE_R - 1) cout << ",";
    }
    cout << endl;
  }
};

int n, m;
vector<P> st;

int solve() {
  // セグメント木 (区間取得を min としたもの)
  // 0 <= s < t <= 50000 なのでセグメント木について n = 500050
  SegTree<int> dp(
      500050, [](int a, int b) { return min(a, b); }, 1e8);

  // 更新
  dp.set(1, 0);
  dp.build();

  rep(i, m) {
    int v = min(dp.get(st[i].second, st[i].second + 1),
                dp.get(st[i].first, st[i].second + 1) + 1);
    dp.set(st[i].second, v);
    dp.build();
  }
  return dp[n];
}

int main() {
  cin >> n >> m;
  st.resize(n);
  rep(i, m) cin >> st[i].first >> st[i].second;
  cout << solve() << endl;
}