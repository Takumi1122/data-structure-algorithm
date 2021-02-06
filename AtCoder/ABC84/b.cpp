#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;

  rep(i, a) {
    if (s[i] == '-') {
      cout << "No" << endl;
      return 0;
    }
  }
  if (s[a] != '-') {
    cout << "No" << endl;
    return 0;
  }
  rep(i, b) {
    if (s[i + a + 1] == '-') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}