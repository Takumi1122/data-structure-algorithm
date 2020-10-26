#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 蟻本P47: Saruman's Army

int main() {
  int n, r;
  cin >> n >> r;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  sort(x.begin(), x.end());
  int i = 0, ans = 0;
  while (i < n) {
    // sはカバーされていない一番左の点の位置
    int s = x[i++];
    // sから距離rを超える点まで進む
    while (i < n && x[i] <= s + r) i++;

    // pは新しく印を付ける点の位置
    int p = x[i - 1];
    // pから距離rを超える点まで進む
    while (i < n && x[i] <= p + r) i++;

    ans++;
  }

  cout << ans << endl;
  return 0;
}