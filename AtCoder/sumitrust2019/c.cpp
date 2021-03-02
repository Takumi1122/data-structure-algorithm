#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int x;
  cin >> x;

  bool ok = false;
  int cnt = x / 100;
  int a = x % 100;
  int mx = cnt * 5;
  int mn = 0;
  if (a <= mx && a >= mn) {
    ok = true;
  }

  if (ok) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}