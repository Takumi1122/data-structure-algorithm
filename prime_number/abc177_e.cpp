#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// coprime 互いに素

/*
    参考リンク
    ABC 177 E - Coprime
      https://atcoder.jp/contests/abc177/tasks/abc177_e
*/

const int A = 1000005;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(A);
  rep(i, n) {
    cin >> a[i];
    c[a[i]]++;
  }

  bool pairwise = true;
  for (int i = 2; i < A; i++) {
    int cnt = 0;
    for (int j = i; j < A; j += i) {
      cnt += c[j];
    }
    if (cnt > 1) pairwise = false;
  }

  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int g = 0;
  rep(i, n) g = gcd(g, a[i]);
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;
  return 0;
}
