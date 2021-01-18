#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int a, b;
  cin >> a >> b;

  for (int i = 1; i <= 999; i++) {
    int h1 = i * (i + 1) / 2;
    int h2 = (i + 1) * (i + 2) / 2;
    if (abs(h2 - h1) == abs(b - a)) {
      cout << h1 - a << endl;
    }
  }
  return 0;
}