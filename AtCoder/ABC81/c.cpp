#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    mp[a]++;
  }

  int ans = 0;
  int cnt = mp.size() - k;
  vector<int> b;
  for (auto p : mp) {
    b.push_back(p.second);
  }
  sort(b.begin(), b.end());
  rep(i, cnt) ans += b[i];

  cout << ans << endl;
  return 0;
}