#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ARC 105 D - Let's Play Nim
      https://atcoder.jp/contests/arc105/tasks/arc105_d
*/

bool solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());

  if (n % 2 == 1) return false;

  bool exist = true;
  for (int i = 0; i < n; i += 2) {
    if (a[i] != a[i + 1]) exist = false;
  }
  if (exist)
    return false;
  else
    return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
}