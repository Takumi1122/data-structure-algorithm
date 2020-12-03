#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];

  vector<int> a(n);
  rep(i, n) a[i] = i + 1;

  map<vector<int>, int> mp;
  do {
    mp[a] = mp.size();
  } while (next_permutation(a.begin(), a.end()));

  int ans = abs(mp[p] - mp[q]);
  cout << ans << endl;
  return 0;
}