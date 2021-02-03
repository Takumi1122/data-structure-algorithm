#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  sort(a.begin(), a.end(), greater<int>());
  int sum1 = 0;
  int sum2 = 0;
  rep(i, n) {
    if (i % 2 == 0) {
      sum1 += a[i];
    } else {
      sum2 += a[i];
    }
  }

  cout << abs(sum1 - sum2) << endl;
  return 0;
}