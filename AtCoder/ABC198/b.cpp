#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

bool isPalindrome(string s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

int main() {
  string s;
  cin >> s;
  rep(i, 100) {
    if (isPalindrome(s)) {
      cout << "Yes" << endl;
      return 0;
    }
    s = '0' + s;
  }
  cout << "No" << endl;
  return 0;
}