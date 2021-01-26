#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 差分を引く
// A0 = An+1 = 0 を追加

int main() {
  int n;
  cin >> n;
  vector<int> a;
  // 始点
  a.push_back(0);
  rep(i, n) {
    int ai;
    cin >> ai;
    a.push_back(ai);
  }
  // 終点
  a.push_back(0);

  int sum = 0;
  rep(i, n + 1) sum += abs(a[i + 1] - a[i]);

  rep(i, n) {
    int ans = sum;
    int ab1 = abs(a[i] - a[i + 1]) + abs(a[i + 1] - a[i + 2]);
    int ab2 = abs(a[i] - a[i + 2]);
    ans -= abs(ab1 - ab2);
    cout << ans << endl;
  }
  return 0;
}