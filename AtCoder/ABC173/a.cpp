#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  while (n > 1000) {
    n = n - 1000;
  }

  cout << 1000 - n << endl;
  return 0;
}