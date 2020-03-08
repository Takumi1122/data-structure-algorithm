#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, m, min;
  cin >> a >> b >> m;
  int A[a], B[b], x[m], y[m], c[m];
  int minA = (1 << 30);
  int minB = (1 << 30);
  int minS;
  rep(i, a) {
    cin >> A[i];
    if (A[i] < minA) minA = A[i];
  }
  rep(i, b) {
    cin >> B[i];
    if (B[i] < minB) minB = B[i];
  }
  minS = minA + minB;
  rep(i, m) {
    cin >> x[i] >> y[i] >> c[i];
    if ((A[x[i]] + B[y[i]] - c[i]) < minS) minS = (A[x[i]] + B[y[i]] - c[i]);
  }

  cout << minS << endl;

  return 0;
}