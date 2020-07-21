#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 計数ソート　o(n + A)

const int MAX = 100000;  // 配列の値は 100000 未満だとします

int main() {
  int n;  // 要素数
  cin >> n;
  vector<int> a(n);  // 整列したい配列ベクトル (サイズ を n に初期化)
  rep(i, n) {
    cin >> a[i];  // 整列したい配列を取得
  }

  /* 各要素の個数をカウントします */
  /* num[v] := v の個数 */
  int num[MAX] = {0};
  rep(i, n) {
    ++num[a[i]];  // a[i] をカウントします
  }

  /* num の累積和をとります */
  /* sum[v] := v 以下の値の個数 */
  int sum[MAX] = {0};
  for (int v = 1; v < MAX; v++) {
    sum[v] = sum[v - 1] + num[v];
  }

  /* sum を元にソート */
  /* sorted: a をソートしたもの */
  vector<int> sorted(n);
  for (int i = n - 1; i >= 0; i--) {
    sorted[--sum[a[i]]] = a[i];
  }

  rep(i, n) cout << sorted[i] << " ";
  cout << endl;

  return 0;
}