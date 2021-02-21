#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  bool ok = true;
  rep(i, s.size()) {
    if (i % 2 == 0 && !islower(s[i])) ok = false;
    if (i % 2 == 1 && !isupper(s[i])) ok = false;
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}