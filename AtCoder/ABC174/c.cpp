#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int k;
  cin >> k;
  if (7 % k == 0) {
    cout << 1 << endl;
    return 0;
  }
  string s = "7";
  for (int i = 1; i <= 1e8; i++) {
    s = s + '7';
    int num = stoi(s);
    if (num % k == 0) {
      cout << i + 1 << endl;
      return 0;
    }
    }
  cout << -1 << endl;
  return 0;
}