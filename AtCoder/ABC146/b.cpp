#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;
  rep(i, s.size()) {
    s[i] += n;
    if (s[i] > 'Z') {
      s[i] -= 26;
    }
  }
  cout << s << endl;
  return 0;
}