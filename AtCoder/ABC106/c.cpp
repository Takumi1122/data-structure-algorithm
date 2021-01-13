#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  int k;
  cin >> s >> k;

  char ans = '1';
  int n = s.size();
  rep(i, min(n, k)) {
    if (s[i] != '1') {
      ans = s[i];
      break;
    }
  }

  cout << ans << endl;
  return 0;
}