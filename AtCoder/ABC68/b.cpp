#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;

  int cnt = -1;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int a = i;
    int c = 0;
    while (a % 2 == 0) {
      c++;
      a /= 2;
    }
    if (c > cnt) {
      ans = i;
      cnt = c;
    }
  }

  cout << ans << endl;
  return 0;
}