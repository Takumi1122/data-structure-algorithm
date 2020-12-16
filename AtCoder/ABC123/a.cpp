#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  vector<int> a(5);
  rep(i, 5) cin >> a[i];
  int k;
  cin >> k;

  rep(i, 5) rep(j, i) {
    if (abs(a[i] - a[j]) > k) {
      cout << ":(" << endl;
      return 0;
    }
  }
  cout << "Yay!" << endl;
  return 0;
}