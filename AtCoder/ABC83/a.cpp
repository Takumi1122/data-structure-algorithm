#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (a + b > c + d) {
    cout << "Left" << endl;
  } else if (a + b == c + d) {
    cout << "Balanced" << endl;
  } else {
    cout << "Right" << endl;
  }
  return 0;
}