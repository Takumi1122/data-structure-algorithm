#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll h, w, c;
  cin >> h >> w;

  if (h == 1 || w == 1) {
    c = 1;
  } else {
    c = ((h + 1) / 2) * ((w + 1) / 2) + (h / 2) * (w / 2);
  }

  cout << c << endl;
  return 0;
}