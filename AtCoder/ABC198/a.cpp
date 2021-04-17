#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
  } else {
    cout << n - 2 + 1 << endl;
  }
  return 0;
}