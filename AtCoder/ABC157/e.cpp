#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// setを上手く使う
// set: データの追加・削除・検索の処理速度が O(log(n))

/*
    参考リンク
    ABC157 E - Simple String Queries
      https://atcoder.jp/contests/abc157/tasks/abc157_e
*/

const int INF = 1 << 30;

int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<set<int> > pls(26, set<int>({INF}));
  rep(i, n) pls[s[i] - 'a'].insert(i);

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
      pls[pc - 'a'].erase(ind);
      pls[nc - 'a'].insert(ind);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      int res = 0;
      rep(c, 26) {
        if (pls[c].empty()) continue;
        int lid = *pls[c].lower_bound(l);
        int rid = *pls[c].lower_bound(r);
        if (rid > lid) ++res;
      }
      cout << res << endl;
    }
  }
}