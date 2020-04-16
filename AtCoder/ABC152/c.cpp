#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  int mn = 0;
  int sum = n;

  rep(i, n) {
    mn = *min_element(p.begin(), p.begin() + i);
    if (p[i] > mn) {
      sum--;
    }
  }

  cout << sum << endl;
  return 0;
}