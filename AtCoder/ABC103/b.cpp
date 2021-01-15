#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size();
  bool ok = false;
  rep(i, n) {
    int cnt = 0;
    rep(j, n) {
      if (s[(j + i) % n] == t[j]) cnt++;
    }
    if (cnt == n) ok = true;
  }

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}