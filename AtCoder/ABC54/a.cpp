#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b;
  cin >> a >> b;

  if (a == 1 || b == 1) {
    if (a == 1 && b == 1) {
      cout << "Draw" << endl;
    } else if (a == 1) {
      cout << "Alice" << endl;
    } else {
      cout << "Bob" << endl;
    }
    return 0;
  }

  if (a > b) {
    cout << "Alice" << endl;
  } else if (a == b) {
    cout << "Draw" << endl;
  } else {
    cout << "Bob" << endl;
  }
  return 0;
}