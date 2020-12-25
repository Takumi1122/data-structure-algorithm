#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 1LL << 40;

// ある量を決めるとどうすべきかがGreedyに決まらないか
// 「こういうものだけ探索すればよい」というのが絞れないか

/*
    参考リンク
    ABC 116 D - Various Sushi
      https://atcoder.jp/contests/abc116/tasks/abc116_d
*/

int main() {
  ll n, k;
  cin >> n >> k;
  // s[i]: 種類iの美味しさの集合
  vector<vector<ll> > s(n);
  rep(i, n) {
    ll t, d;
    cin >> t >> d;
    --t;
    s[t].push_back(d);
  }

  // 各種類について,美味しい順に並べる
  for (auto &v : s) {
    sort(v.begin(), v.end(), greater<ll>());
    if (v.empty()) v.push_back(-INF);
  }

  // 「美味しさの最大値」の大きいネタ順
  sort(s.begin(), s.end(),
       [&](vector<ll> a, vector<ll> b) { return a[0] > b[0]; });

  // まずK種類選ぶ場合
  ll now = 0;
  priority_queue<ll> que;
  rep(i, k) {
    now += s[i][0];
    for (int j = 1; j < s[i].size(); ++j) que.push(s[i][j]);
  }
  for (int i = k; i < n; ++i)
    for (int j = 0; j < s[i].size(); ++j) que.push(s[i][j]);

  // 走査
  ll ans = now + k * k;
  for (ll x = k - 1; x >= 1; --x) {
    ll v = s[x][0];
    ll w = que.top();
    if (v < w) {
      que.pop();
      now += w;
      que.push(v);
      now -= v;
    }
    ans = max(ans, now + x * x);
  }

  cout << ans << endl;
  return 0;
}