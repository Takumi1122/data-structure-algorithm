#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (i * j == n) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}