#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

vector<int> g[100005];
vector<int> c;
vector<int> ans;
multiset<int> st;

void dfs(int v, int d = 0, int p = -1) {
  for (int u : g[v]) {
    if (u == p) continue;
    if (!st.count(c[u])) {
      ans.push_back(u + 1);
    }
    st.insert(c[u]);
    dfs(u, d + 1, v);
    st.erase(st.find(c[u]));
  }
}

int main() {
  int n;
  cin >> n;
  c.resize(n, 0);
  rep(i, n) cin >> c[i];
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  st.insert(c[0]);
  ans.push_back(1);
  dfs(0, 0, -1);
  sort(ans.begin(), ans.end());
  rep(i, ans.size()) cout << ans[i] << endl;
  return 0;
}