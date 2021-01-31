#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (c == 0) {
    if (a <= b) {
      cout << "Aoki" << endl;
    } else {
      cout << "Takahashi" << endl;
    }
  } else {
    if (b <= a) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
  }
  return 0;
}