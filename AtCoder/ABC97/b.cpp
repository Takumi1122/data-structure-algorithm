#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int x;
  cin >> x;

  int ans = 1;
  for (int i = 2; i <= x; i++) {
    int pw = i * i;
    while (pw <= x) {
      ans = max(ans, pw);
      pw *= i;
    }
  }

  cout << ans << endl;
  return 0;
}