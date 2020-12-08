#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P275: Euclid's Game

int main() {
  int a, b;
  cin >> a >> b;
  bool f = true;

  for (;;) {
    if (a > b) swap(a, b);

    if (b % a == 0) break;

    if (b - a > a) break;

    b -= a;
    f = !f;
  }

  if (f)
    cout << "Stan wins" << endl;
  else
    cout << "Ollie wins" << endl;
  return 0;
}