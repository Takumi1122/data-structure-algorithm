#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  rep(i, n - 2) {
    string t = s.substr(i, 3);
    if (t == "ABC") ans++;
  }
  cout << ans << endl;
  return 0;
}