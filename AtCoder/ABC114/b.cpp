#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int ans = 1e9;
  rep(i, n - 2) {
    string s1 = s.substr(i, 3);
    int a = stoi(s1);
    ans = min(ans, abs(753 - a));
  }

  cout << ans << endl;
  return 0;
}