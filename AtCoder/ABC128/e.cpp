#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// イベントソート
// 通行止めの影響を受ける可能性があるのは
// [Si − Xi, Ti − Xi)の間に座標0を出発した人だけ

/*
    参考リンク
    ABC 128 E - Roadwork
      https://atcoder.jp/contests/abc128/tasks/abc128_e
*/

using type = pair<int, ll>;  // 1: query, 0; delete, -1: insert
using event = pair<ll, type>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<event> v;
  rep(i, n) {
    int s, t, x;
    cin >> s >> t >> x;
    v.push_back({s - x, type(-1, x)});
    v.push_back({t - x, type(0, x)});
  }
  rep(i, q) {
    int d;
    cin >> d;
    v.push_back({d, type(1, i)});
  }
  sort(v.begin(), v.end());

  vector<ll> res(q);
  multiset<ll> se;
  for (auto p : v) {
    ll x = p.first;
    int type = p.second.first;
    ll val = p.second.second;
    if (type == -1)
      se.insert(val);
    else if (type == 0)
      se.erase(se.lower_bound(val));
    else
      res[val] = (se.empty() ? -1 : *(se.begin()));
  }
  for (auto v : res) cout << v << endl;
  return 0;
}