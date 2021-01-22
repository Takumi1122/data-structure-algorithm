#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  rep(i, 3) {
    if (s[i] == 'o') cnt++;
  }

  cout << 700 + 100 * cnt << endl;
  return 0;
}