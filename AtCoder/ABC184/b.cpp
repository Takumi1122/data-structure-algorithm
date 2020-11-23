#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x;
  string s;
  cin >> n >> x >> s;
  rep(i, s.size()) {
    if (s[i] == 'o') {
      x++;
    } else {
      if (x > 0) x--;
    }
  }
  cout << x << endl;
  return 0;
}