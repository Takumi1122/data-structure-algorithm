#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string a, b;
  cin >> a >> b;
  if (a.size() == b.size()) {
    if (a > b) {
      cout << "GREATER" << endl;
    } else if (a == b) {
      cout << "EQUAL" << endl;
    } else {
      cout << "LESS" << endl;
    }
  } else {
    if (a.size() > b.size()) {
      cout << "GREATER" << endl;
    } else {
      cout << "LESS" << endl;
    }
  }
  return 0;
}