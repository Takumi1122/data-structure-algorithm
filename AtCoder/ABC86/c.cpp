#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> t(n), x(n), y(n);
  rep(i, n) cin >> t[i] >> x[i] >> y[i];

  int pret = 0;
  int prep = 0;
  rep(i, n) {
    int abt = abs(t[i] - pret);
    int abp = abs((x[i] + y[i]) - prep);
    if (abt < abp) {
      cout << "No" << endl;
      return 0;
    }
    if (abs(abt - abp) % 2 == 1) {
      cout << "No" << endl;
      return 0;
    }
    pret = t[i];
    prep = x[i] + y[i];
  }

  cout << "Yes" << endl;
  return 0;
}