#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 126 F - XOR Matching
      https://atcoder.jp/contests/abc126/tasks/abc126_f
*/

void solve(int m, int k) {
  if (m == 0) {
    if (k != 0)
      cout << -1 << endl;
    else
      cout << "0 0" << endl;
    return;
  }

  if (m == 1) {
    if (k != 0)
      cout << -1 << endl;
    else
      cout << "0 0 1 1" << endl;
    return;
  }

  if (k >= (1 << m)) {
    cout << -1 << endl;
    return;
  }

  if (k == 0) {
    for (int bit = 0; bit < (1 << m); ++bit) {
      cout << bit << " ";
    }
    for (int bit = (1 << m) - 1; bit >= 0; --bit) {
      cout << bit << " ";
    }
    cout << endl;
    return;
  }

  vector<P> v;
  for (int bit = 0; bit < (1 << m); ++bit) {
    v.push_back(P(min(bit, bit ^ k), max(bit, bit ^ k)));
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for (int i = 0; i < v.size(); i += 2) {
    cout << v[i].first << " " << v[i].second << " " << v[i + 1].first << " "
         << v[i + 1].second << " " << v[i].second << " " << v[i].first << " "
         << v[i + 1].second << " " << v[i + 1].first << " ";
  }
  cout << endl;
}

int main() {
  int m, k;
  cin >> m >> k;
  solve(m, k);
}