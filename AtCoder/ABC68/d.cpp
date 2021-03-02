#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 全ての要素に1回ずつ操作を行うと、全て均等に-1される

/*
    参考リンク
    ABC 68 D - Decrease (Contestant ver.)
      https://atcoder.jp/contests/abc068/tasks/arc079_b
*/

int main() {
  ll k;
  cin >> k;

  vector<ll> ans;

  ll d = k % 50;
  rep(i, 50 - d) ans.push_back(49 - d);
  rep(i, d) ans.push_back(50);

  ll a = k / 50;
  rep(i, 50) ans[i] += a;

  cout << ans.size() << endl;
  rep(i, 50) cout << ans[i] << endl;
  return 0;
}