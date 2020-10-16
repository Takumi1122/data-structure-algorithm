#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P278: Georgia and Bob

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  if (n % 2 == 1) p.push_back(0);

  sort(p.begin(), p.end());

  int x = 0;
  for (int i = 0; i < n - 1; i++) {
    x ^= (p[i + 1] - p[i] - 1);
  }

  if (x == 0)
    cout << "Bob will win" << endl;
  else
    cout << "Georgia will win" << endl;
  return 0;
}