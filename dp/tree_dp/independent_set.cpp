#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    Educational DP Contest P - Independent Set
      https://atcoder.jp/contests/dp/tasks/dp_p
*/

const int mod = 1000000007;
vector<int> G[100009];
ll white[100009], black[100009];

void dfs(int u, int p) {
  black[u] = 1;
  white[u] = 1;
  for (int v : G[u]) {
    if (v == p) continue;
    dfs(v, u);
    black[u] *= white[v];
    black[u] %= mod;
    white[u] *= white[v] + black[v];
    white[u] %= mod;
  }
}

int main() {
  int n;
  cin >> n;
  rep(i, n - 1) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0, -1);

  cout << (black[0] + white[0]) % mod << endl;

  return 0;
}