#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int c = 0;
  if (s.size() % 2 == 0) {
    for (int i = 1; i <= s.size() / 2; i++) {
      if (s[s.size() / 2 - i] != s[s.size() / 2 + i - 1]) {
        c++;
      }
    }
  } else {
    for (int i = 1; i <= s.size() / 2; i++) {
      if (s[s.size() / 2 - i] != s[s.size() / 2 + i]) {
        c++;
      }
    }
  }
  cout << c << endl;
  return 0;
}