#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a;
  cin >> a;

  int l = a / 100;
  int r = a % 100;
  if (1 <= l && l <= 12) {
    if (1 <= r && r <= 12)
      cout << "AMBIGUOUS" << endl;
    else
      cout << "MMYY" << endl;
  } else {
    if (1 <= r && r <= 12)
      cout << "YYMM" << endl;
    else
      cout << "NA" << endl;
  }

  return 0;
}