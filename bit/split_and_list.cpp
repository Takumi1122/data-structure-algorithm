#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 半分全列挙 o(2^(n/2) * N)

int main() {
  // 入力
  int n, s;
  cin >> n >> s;
  vector<int> num(n);
  rep(i, n) cin >> num[i];

  // グループ１をビット全探索で全列挙 (前半の半分)
  vector<int> A;
  for (int bit = 0; bit < (1 << n / 2); bit++) {
    int sum = 0;
    rep(i, n / 2) {
      int mask = 1 << i;
      if (bit & mask) {
        sum += num[i];
      }
    }
    A.push_back(sum);
  }
  // グループ2をビット全探索で全列挙 (後半の半分)
  vector<int> B;
  for (int bit = 0; bit < (1 << n / 2); bit++) {
    int sum = 0;
    rep(i, n / 2) {
      int mask = 1 << i;
      if (bit & mask) {
        sum += num[n / 2 + i];
      }
    }
    B.push_back(sum);
  }

  sort(B.begin(), B.end());  // B をソート
  // A の要素を固定して二分探索
  int ans = 0;
  for (auto a : A) {
    if (s - a >= 0) {
      ans = max(ans, a + *(upper_bound(B.begin(), B.end(), s - a) - 1));
    }
  }
  cout << ans << endl;
  return 0;
}
