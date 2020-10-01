#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

// 挿入ソート o(n^2) 安定ソート○　内部ソート○

int main() {
  // 入力
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // 挿入ソート
  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i;
    for (; j > 0; j--) {
      if (a[j - 1] > v) {
        a[j] = a[j - 1];
      } else
        break;
    }
    a[j] = v;
  }

  // 出力
  rep(i, n) cout << a[i] << ", ";
  cout << endl;

  return 0;
}