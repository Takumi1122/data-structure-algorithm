#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  /* 入力受け取り */
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  /* しゃくとり法 */
  ll res = 0;
  int right = 0;
  int sum = 0;  // AND 和
  rep(left, n) {
    while (right < n && (sum ^ a[right]) == (sum + a[right])) {
      sum += a[right];
      ++right;
    }
    res += right - left;
    if (left == right)
      ++right;
    else {
      sum -= a[left];  // a[left] を削除 (sum ^= a[left] でも OK)
    }
  }

  cout << res << endl;
}