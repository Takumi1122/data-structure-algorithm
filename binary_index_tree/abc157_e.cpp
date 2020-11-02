#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC157 E - Simple String Queries
      https://atcoder.jp/contests/abc157/tasks/abc157_e
*/

template <class Abel>
struct BIT {
  const Abel UNITY_SUM = 0;  // to be set
  vector<Abel> dat;

  /* [1, n] */
  BIT(int n) : dat(n + 1, UNITY_SUM) {}
  void init(int n) { dat.assign(n + 1, UNITY_SUM); }

  /* a is 1-indexed */
  inline void add(int a, Abel x) {
    for (int i = a; i < (int)dat.size(); i += i & -i) dat[i] = dat[i] + x;
  }

  /* [1, a], a is 1-indexed */
  inline Abel sum(int a) {
    Abel res = UNITY_SUM;
    for (int i = a; i > 0; i -= i & -i) res = res + dat[i];
    return res;
  }

  /* [a, b), a and b are 1-indexed */
  inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }

  /* debug */
  void print() {
    for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
    cout << endl;
  }
};

const int INF = 1 << 30;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<BIT<int>> pls(26, BIT<int>(n + 10));
  rep(i, n) pls[s[i] - 'a'].add(i + 1, 1);
  rep(i, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int ind;
      char nc;
      cin >> ind >> nc;
      --ind;
      auto pc = s[ind];
      s[ind] = nc;
      pls[pc - 'a'].add(ind + 1, -1);
      pls[nc - 'a'].add(ind + 1, 1);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      int res = 0;
      for (int c = 0; c < 26; ++c)
        if (pls[c].sum(l + 1, r + 1)) ++res;
      cout << res << endl;
    }
  }
}