#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) { cin >> a[i]; }
  int s = 0;
  int c = 0;
  rep(i, n) { s += a[i]; }
  rep(i, n) {
    if (4 * m * a[i] >= s) {
      c++;
    }
  }
  if (c >= m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}