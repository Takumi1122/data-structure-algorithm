#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int a;
    cin >> a;
    mp[a]++;
  }

  vector<ll> b;
  for (auto p : mp) {
    int cnt = p.second / 2;
    rep(i, cnt) b.push_back(p.first);
  }

  sort(b.begin(), b.end(), greater<ll>());
  if (b.size() <= 1) {
    cout << 0 << endl;
  } else {
    cout << b[0] * b[1] << endl;
  }
  return 0;
}