#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> a;
  rep(i, n) {
    int an;
    cin >> an;
    a.push(an);
  }

  rep(i, m) {
    int cs = a.top();
    a.pop();
    cs /= 2;
    a.push(cs);
  }

  ll ans = 0;
  rep(i, n) {
    int cs = a.top();
    ans += cs;
    a.pop();
  }

  cout << ans << endl;
  return 0;
}