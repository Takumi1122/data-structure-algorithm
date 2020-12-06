#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ARC 110 C - Exoswap
      https://atcoder.jp/contests/arc110/tasks/arc110_c
*/

int n;
vector<int> p, ip;

bool solve(int left, vector<int> &res) {
  if (res.size() == n - 1) {
    rep(i, n) if (p[i] != i) return false;
    return true;
  }

  if (ip[left] <= left) return false;
  for (int j = ip[left]; j > left; --j) {
    res.push_back(j);
    swap(p[j], p[j - 1]);
  }

  for (int j = left; j < ip[left]; ++j)
    if (p[j] != j) return false;
  return solve(ip[left], res);
}

int main() {
  cin >> n;
  p.resize(n), ip.resize(n);
  rep(i, n) {
    cin >> p[i];
    --p[i];
    ip[p[i]] = i;
  }

  vector<int> res;
  if (!solve(0, res))
    cout << -1 << endl;
  else
    for (auto v : res) cout << v << endl;
}