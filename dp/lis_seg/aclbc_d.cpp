#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ACL Beginner Contest D - Flat Subsequence
      https://atcoder.jp/contests/abl/tasks/abl_d

    LIS でも大活躍！ DP の配列使いまわしテクニックを特集
      https://qiita.com/drken/items/68b8503ad4ffb469624c
*/

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

int solve(const vector<int> &a, int k) {
  int n = (int)a.size();

  // セグメント木 (区間取得を max としたもの)
  // 0 <= a[i] <=300000 なのでセグメント木について n = 300050
  SegTree<int> dp(
      300050, [](int a, int b) { return max(a, b); }, 0);

  // 更新
  int res = 0;
  rep(i, n) {
    int h1 = max(a[i] - k, 0);
    int h2 = min(a[i] + k, 300040);
    // 値取得
    int A = dp.get(h1, h2 + 1);

    // 更新
    if (dp.get(a[i], a[i] + 1) < A + 1) {
      dp.update(a[i], A + 1);
      res = max(res, A + 1);
    }
  }
  return res;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  cout << solve(a, k) << endl;
}