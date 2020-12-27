#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(m), y(m);
  rep(i, m) {
    cin >> p[i] >> y[i];
    p[i]--;
  }

  vector<vector<int> > vals(n);
  rep(i, m) vals[p[i]].push_back(y[i]);

  rep(i, n) {
    sort(vals[i].begin(), vals[i].end());
    vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
  }

  rep(i, m) {
    int v = p[i];
    printf("%06d", v + 1);

    int id =
        lower_bound(vals[v].begin(), vals[v].end(), y[i]) - vals[v].begin();
    printf("%06d\n", id + 1);
  }
}