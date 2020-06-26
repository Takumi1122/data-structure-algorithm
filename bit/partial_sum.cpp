#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  // 全探索 --- bit は {0, 1, ..., n-1} の 2^n 通りの部分集合全体を動きます。
  bool exist = false;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int sum = 0;  // 部分集合の和
    rep(i, n) {
      if (bit & (1 << i)) {  // i が S に入っているなら足す
        sum += a[i];
      }
    }

    // sum が K に一致するか
    if (sum == k) exist = true;
  }

  if (exist)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}