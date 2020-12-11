#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  n %= 10;

  if (n == 3) {
    cout << "bon" << endl;
  } else if (n == 0 || n == 1 || n == 6 || n == 8) {
    cout << "pon" << endl;
  } else {
    cout << "hon" << endl;
  }
  return 0;
}