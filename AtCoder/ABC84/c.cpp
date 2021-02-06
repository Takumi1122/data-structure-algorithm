#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// n <= 500 O(n^2)

/*
    参考リンク
    ABC 84 C - Special Trains
      https://atcoder.jp/contests/abc084/tasks/abc084_c
*/

int main() {
  int n;
  cin >> n;
  vector<int> c(n - 1), s(n - 1), f(n - 1);
  rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];

  rep(i, n) {
    int t = 0;
    for (int j = i; j < n - 1; j++) {
      if (t < s[j])
        t = s[j];
      else if (t % f[j] == 0)
        ;
      else
        t = t + f[j] - t % f[j];
      t += c[j];
    }
    cout << t << endl;
  }
  return 0;
}