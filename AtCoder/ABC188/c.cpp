#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
  int n;
  cin >> n;
  int n1 = 1 << n;
  vector<P> a(n1);
  rep(i, n1) {
    int ai;
    cin >> ai;
    a[i].first = i + 1;
    a[i].second = ai;
  }

  while (n1 > 2) {
    vector<P> a1;
    for (int i = 0; i < n1; i += 2) {
      if (a[i].second > a[i + 1].second) {
        a1.emplace_back(a[i]);
      } else {
        a1.emplace_back(a[i + 1]);
      }
    }
    a = a1;
    n1 /= 2;
  }

  if (a[0].second > a[1].second) {
    cout << a[1].first << endl;
  } else {
    cout << a[0].first << endl;
  }
  return 0;
}