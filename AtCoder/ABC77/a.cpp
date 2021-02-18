#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  reverse(s1.begin(), s1.end());
  if (s1 == s2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}