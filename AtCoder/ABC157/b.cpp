#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int a[3][3], b[10];
bool ap[3][3];

int main() {
  rep(i, 3) rep(j, 3) cin >> a[i][j];
  int n;
  cin >> n;
  rep(i, n) cin >> b[i];

  rep(i, 3) rep(j, 3) rep(k, n) {
    if (a[i][j] == b[k]) ap[i][j] = true;
  }

  bool ok = false;
  rep(i, 3) {
    if (ap[i][0] && ap[i][1] && ap[i][2]) ok = true;
  }
  rep(i, 3) {
    if (ap[0][i] && ap[1][i] && ap[2][i]) ok = true;
  }
  if (ap[0][0] && ap[1][1] && ap[2][2]) ok = true;
  if (ap[0][2] && ap[1][1] && ap[2][0]) ok = true;

  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}