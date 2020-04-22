#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  map<string, int> m;
  rep(i, n) {
    cin >> s[i];
    if (m.count(s[i]) != 0) {
      m[s[i]]++;
    } else {
      m.insert(make_pair(s[i], 1));
    }
  }

  int mx = 0;

  for (auto it = m.begin(); it != m.end(); ++it) {
    mx = max(it->second, mx);
  }

  for (auto it = m.begin(); it != m.end(); ++it) {
    if (it->second == mx) {
      cout << it->first << endl;
    }
  }

  return 0;
}