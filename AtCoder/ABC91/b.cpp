#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, m;
  cin >> n;
  map<string, int> mp;
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
  }
  cin >> m;
  rep(i, m) {
    string t;
    cin >> t;
    mp[t]--;
  }

  int ans = 0;
  for (auto p : mp) {
    ans = max(ans, p.second);
  }

  cout << ans << endl;
  return 0;
}