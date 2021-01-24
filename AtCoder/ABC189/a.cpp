#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;

  rep(i, 3) {
    if (s[0] != s[i]) {
      cout << "Lost" << endl;
      return 0;
    }
  }

  cout << "Won" << endl;
  return 0;
}