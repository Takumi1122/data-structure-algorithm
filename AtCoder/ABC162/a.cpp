#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  bool b = false;
  cin >> n;
  while (n) {
    if (n % 10 == 7) {
      b = true;
    }
    n /= 10;
  }

  if (b) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}