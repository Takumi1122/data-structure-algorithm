#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  rep(i, s.size() - 1) {
    if (s[i] == s[i + 1]) {
      cout << "Bad" << endl;
      return 0;
    }
  }
  cout << "Good" << endl;
  return 0;
}