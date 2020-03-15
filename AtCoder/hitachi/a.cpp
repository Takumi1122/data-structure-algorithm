#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  rep(i, s.size()) {
    if (s[i] + s[i + 1] == "hi" && s[i] + s[i + 1] + s[i + 2] != "hii") {
      cout << "Yes" << endl;
      break;
    }
  }

  cout << "No" << endl;
  return 0;
}