#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  if (s[0] == s[1] && s[1] == s[2]) {
    cout << "Yes" << endl;
  } else if (s[1] == s[2] && s[2] == s[3]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}