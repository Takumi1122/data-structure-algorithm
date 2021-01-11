#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  ll n, C;
  cin >> n >> C;
  vector<P> events;
  rep(i, n) {
    int a, b, c;
    cin >> a >> b >> c;
    events.emplace_back(a, c);
    events.emplace_back(b + 1, -c);
  }

  sort(events.begin(), events.end());
  ll ans = 0;
  ll s = 0;
  int pre = 0;
  for (auto event : events) {
    ans += min<ll>(C, s) * (event.first - pre);
    s += event.second;
    pre = event.first;
  }

  cout << ans << endl;
  return 0;
}