#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

bool is_integer(double x) { return floor(x) == x; }

int main() {
  int n;
  cin >> n;
  while (n) {
    double x = sqrt(n);
    if (is_integer(x)) {
      cout << n << endl;
      return 0;
    }
    n--;
  }
  return 0;
}