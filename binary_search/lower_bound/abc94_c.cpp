#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 中央値 二分探索

/*
    参考リンク
    ABC 94 C - Many Medians
      https://atcoder.jp/contests/abc094/tasks/arc095_a
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> as = a;
  sort(a.begin(), a.end());
  int a1 = a[n / 2 - 1];
  int a2 = a[n / 2];

  rep(i, n) {
    int id = lower_bound(a.begin(), a.end(), as[i]) - a.begin();
    if (id <= n / 2 - 1) {
      cout << a2 << endl;
    } else {
      cout << a1 << endl;
    }
  }
  return 0;
}