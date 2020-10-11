#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];

  int ans = 0;
  set<int> s;
  rep(i, n) {
    int pi = p[i];
    s.insert(pi);
    while (s.count(ans)) ans++;
    cout << ans << endl;
  }
  return 0;
}