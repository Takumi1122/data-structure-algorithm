#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 198 E - Unique Color
      https://atcoder.jp/contests/abc198/tasks/abc198_e
*/

vector<int> c;
vector<vector<int>> to;
vector<int> cnt;
vector<int> ans;

void dfs(int v, int p = -1) {
  if (cnt[c[v]] == 0) ans.push_back(v + 1);
  cnt[c[v]]++;
  for (int u : to[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  cnt[c[v]]--;
}

int main() {
  int n;
  cin >> n;
  c = vector<int>(n);
  rep(i, n) cin >> c[i];
  to.resize(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  cnt = vector<int>(100001);
  dfs(0);

  sort(ans.begin(), ans.end());
  for (int v : ans) cout << v << endl;
  return 0;
}