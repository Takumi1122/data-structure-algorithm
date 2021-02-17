#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  char x, y;
  cin >> x >> y;
  int x1 = x - 'A';
  int y1 = y - 'A';
  if (x1 < y1) {
    cout << '<' << endl;
  } else if (x1 == y1) {
    cout << '=' << endl;
  } else {
    cout << '>' << endl;
  }
  return 0;
}