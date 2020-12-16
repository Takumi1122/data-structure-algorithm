#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << a + b << endl;
  } else {
    int c = max(a, b);
    cout << c + c - 1 << endl;
  }
  return 0;
}