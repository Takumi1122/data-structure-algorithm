#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  string ans = "";
  int n = s.size();
  int num = -1;
  rep(i, n) {
    if (s[i] == '.') num = i;
  }

  if (num == -1) {
    cout << s << endl;
  } else {
    cout << s.substr(0, num) << endl;
  }
  return 0;
}