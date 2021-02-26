#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int four = 0;
  int two = 0;
  rep(i, n) {
    if (a[i] % 4 == 0) {
      four++;
      continue;
    }
    if (a[i] % 2 == 0) {
      two++;
      continue;
    }
  }

  if (n / 2 <= four) {
    cout << "Yes" << endl;
    return 0;
  }
  if (four * 2 + two >= n) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
  return 0;
}