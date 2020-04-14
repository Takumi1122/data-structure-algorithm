#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n), q(n);
  rep(i, n) cin >> p[i];
  rep(i, n) cin >> q[i];
  int pv = 0, qv = 0;
  rep(i, n) {
    pv += p[i] * pow(10, n - 1 - i);
    qv += q[i] * pow(10, n - 1 - i);
  }
  vector<int> x(n, 0), y;
  int c = 0;
  for (int i = 0; i < n; i++) x[i] = i + 1;
  do {
    rep(i, n) {
      if (i == 0) {
        y.push_back(0);
        y[c] += x[i];
      } else {
        y[c] += x[i] * pow(10, i);
      }
    }
    c++;
  } while (next_permutation(x.begin(), x.end()));

  sort(y.begin(), y.end());
  int np, nq;

  auto itr1 = find(y.begin(), y.end(), pv);
  np = itr1 - y.begin();
  np++;
  auto itr2 = find(y.begin(), y.end(), qv);
  nq = itr2 - y.begin();
  nq++;

  cout << abs(np - nq) << endl;

  return 0;
}