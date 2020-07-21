#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;          // 要素数
  int a[100000];  // 要素数 100000 以下とします
  cin >> n;
  rep(i, n) cin >> a[i];

  sort(a, a + n);  // a[0:N] を小さい順にソート

  // 出力
  rep(i, n) cout << a[i] << " ";
  cout << endl;
}