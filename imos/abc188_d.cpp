#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// mapによるimos法
// 配列サイズが大きい場合に使用(10^9)
// std::mapの内部ではキーが昇順になるよう要素がソートされている

/*
    参考リンク
    ABC 188 D - Snuke Prime
      https://atcoder.jp/contests/abc188/tasks/abc188_d
*/

int main() {
  ll n, C;
  cin >> n >> C;
  map<int, ll> events;
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    events[a] += c;
    events[b + 1] -= c;
  }

  ll ans = 0;
  ll s = 0;
  int pre = 0;
  for (auto event : events) {
    ans += min(C, s) * (event.first - pre);
    s += event.second;
    pre = event.first;
  }

  cout << ans << endl;
  return 0;
}