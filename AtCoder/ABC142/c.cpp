#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<P> a(n);
  rep(i, n) {
    int a1;
    cin >> a1;
    a[i].first = a1;
    a[i].second = i;
  }

  sort(a.begin(), a.end());

  rep(i, n) cout << a[i].second + 1 << endl;

  return 0;
}