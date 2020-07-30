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
  if (n % 2 == 1) {
    cout << "No" << endl;
  } else {
    string s1 = s.substr(0, n / 2);
    string s2 = s.substr(n / 2);
    if (s1 == s2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}