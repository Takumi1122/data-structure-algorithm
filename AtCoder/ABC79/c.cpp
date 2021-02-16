#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  string s;
  cin >> s;
  int a = (s[0] - '0');
  int b = (s[1] - '0');
  int c = (s[2] - '0');
  int d = (s[3] - '0');

  if (a + b + c + d == 7) {
    printf("%d+%d+%d+%d=7\n", a, b, c, d);
    return 0;
  }
  if (a - b + c + d == 7) {
    printf("%d-%d+%d+%d=7\n", a, b, c, d);
    return 0;
  }
  if (a + b - c + d == 7) {
    printf("%d+%d-%d+%d=7\n", a, b, c, d);
    return 0;
  }
  if (a + b + c - d == 7) {
    printf("%d+%d+%d-%d=7\n", a, b, c, d);
    return 0;
  }
  if (a - b - c + d == 7) {
    printf("%d-%d-%d+%d=7\n", a, b, c, d);
    return 0;
  }
  if (a + b - c - d == 7) {
    printf("%d+%d-%d-%d=7\n", a, b, c, d);
    return 0;
  }
  if (a - b + c - d == 7) {
    printf("%d-%d+%d-%d=7\n", a, b, c, d);
    return 0;
  }
  if (a - b - c - d == 7) {
    printf("%d-%d-%d-%d=7\n", a, b, c, d);
    return 0;
  }
  return 0;
}