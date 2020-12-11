#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, int>;

/*
    参考リンク
    ABC 170 F - Pond Skater
      https://atcoder.jp/contests/abc170/tasks/abc170_f
*/

const ll INF = 1e18;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int si, sj, ti, tj;
  cin >> si >> sj >> ti >> tj;
  --si;
  --sj;
  --ti;
  --tj;
  vector<string> g(h);
  rep(i, h) cin >> g[i];

  auto toId = [&](int i, int j, int v) { return (i * w + j) * 4 + v; };
  auto modCeilK = [&](ll x) { return (x + k - 1) / k * k; };

  vector<ll> dist(h * w * 4, INF);
  priority_queue<LP, vector<LP>, greater<LP>> q;
  auto push = [&](int i, int j, int v, ll x) {
    int id = toId(i, j, v);
    if (dist[id] <= x) return;
    dist[id] = x;
    q.emplace(x, id);
  };
  rep(v, 4) push(si, sj, v, 0);
  while (!q.empty()) {
    ll d = q.top().first;
    int id = q.top().second;
    q.pop();
    if (dist[id] != d) continue;
    int i = id / w / 4;
    int j = id / 4 % w;
    int v = id % 4;
    rep(nv, 4) push(i, j, nv, modCeilK(d));
    {
      int ni = i + di[v], nj = j + dj[v];
      if (0 <= ni && ni < h && 0 <= nj && nj < w) {
        if (g[ni][nj] == '.') {
          push(ni, nj, v, d + 1);
        }
      }
    }
  }

  ll ans = INF;
  rep(v, 4) ans = min(ans, dist[toId(ti, tj, v)]);
  if (ans == INF) {
    cout << -1 << endl;
  } else {
    ans = modCeilK(ans) / k;
    cout << ans << endl;
  }
  return 0;
}