#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int x;
  cin >> x;

  rep(i, x + 1) {
    int rest = x - i * 100;
    if (0 <= rest && rest <= 5 * i) {
      puts("1");
      return 0;
    }
    if (rest < 0) break;
  }
  puts("0");
  return 0;
}