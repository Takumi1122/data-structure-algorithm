#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int c1 = 0;
  vector<vector<int>> x(1000);
  for (int i = 123; i < 1000; ++i) {
    if (i % 10 > (i / 10) % 10 > ((i / 10) / 10) % 10 &&
        i % 10 - (i / 10) % 10 != (i / 10) % 10 - ((i / 10) / 10) % 10) {
      x[c1][0] = ((i / 10) / 10) % 10;
      x[c1][1] = (i / 10) % 10;
      x[c1][2] = i % 10;
      c1++;
    }
  }

  int c2 = 0;
  for (int i = 0; i < x.size(); ++i) {
    if (s.size() >= x[i][2] && s[x[i][0]] != s[x[i][1]] &&
        s[x[i][0]] != s[x[i][2]] && s[x[i][1]] != s[x[i][2]]) {
      c2++;
    }
  }
  cout << c2 << endl;

  return 0;
}
