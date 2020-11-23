#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  ll abr = abs(r1 - r2);
  ll abc = abs(c1 - c2);

  if (abr == 0 && abc == 0) {
    cout << 0 << endl;
    return 0;
  }

  if (abr + abc <= 3 || abr == abc) {
    cout << 1 << endl;
    return 0;
  }

  if (abs(abr - abc) <= 3 || (abr + abc) % 2 == 0 || abr + abc <= 6) {
    cout << 2 << endl;
    return 0;
  }

  cout << 3 << endl;
  return 0;
}