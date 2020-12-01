#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int A, B, m;
  cin >> A >> B >> m;
  vector<int> a(A);
  vector<int> b(B);
  int ma = 1e9;
  int mb = 1e9;
  rep(i, A) {
    cin >> a[i];
    ma = min(ma, a[i]);
  }
  rep(i, B) {
    cin >> b[i];
    mb = min(mb, b[i]);
  }
  int ms = ma + mb;

  rep(i, m) {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    ms = min(ms, a[x] + b[y] - c);
  }

  cout << ms << endl;
  return 0;
}