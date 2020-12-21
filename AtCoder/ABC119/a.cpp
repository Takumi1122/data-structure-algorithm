#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  string m = s.substr(5, 2);
  bool ok = false;
  if (m[0] - '0' >= 1) ok = true;
  if (m[1] - '0' >= 5) ok = true;

  if (ok) {
    cout << "TBD" << endl;
  } else {
    cout << "Heisei" << endl;
  }
  return 0;
}