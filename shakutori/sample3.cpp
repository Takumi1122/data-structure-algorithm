#include <iostream>
#include <vector>
using namespace std;

int main() {
  /* クエリ回数 */
  int Q;
  cin >> Q;

  for (int query = 0; query < Q; ++query) {
    /* 入力受け取り */
    int n;
    cin >> n;
    long long x;
    cin >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    /* 区間の長さの最小値 */
    int res = n + 1;  // 上界を入れておく

    /* 区間の左端 left で場合分け */
    int right = 0;
    long long sum = 0;
    for (int left = 0; left < n; ++left) {
      /* [left, right) の総和が x 以上となる最小の right を求める */
      while (right < n && sum < x) {
        sum += a[right];
        ++right;
      }

      /* 更新 */
      if (sum < x) break;  // これ以上 left を進めてもダメ
      res = min(res, right - left);

      /* left をインクリメントする準備 */
      if (right == left)
        ++right;  // right が left に重なったら right も動かす
      else
        sum -= a[left];  // left のみがインクリメントされるので sum から a[left]
                         // を引く
    }

    /* res = n+1 のときは解なし */
    if (res < n + 1)
      cout << res << endl;
    else
      cout << 0 << endl;
  }
}