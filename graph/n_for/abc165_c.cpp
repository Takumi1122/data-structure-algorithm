#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 165 C - Many Requirements
      https://atcoder.jp/contests/abc165/tasks/abc165_c
*/

int n, m, q;
ll ans = 0;
vector<ll> a, b, c, d;

ll score(vector<int> &A) {
  ll res = 0;
  rep(i, q) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
  return res;
}

void dfs(vector<int> &A) {
  if (A.size() == n) {
    ans = max(ans, score(A));
    return;
  }

  int prev_last = (A.empty() ? 1 : A.back());
  for (int add = prev_last; add <= m; ++add) {
    A.push_back(add);
    dfs(A);
    A.pop_back();
  }
}

int main() {
  cin >> n >> m >> q;
  a = b = c = d = vector<ll>(q);
  rep(i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i], --b[i];
  }
  vector<int> A;
  dfs(A);
  cout << ans << endl;
}