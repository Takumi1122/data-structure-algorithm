#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続する部分列のうち、「xor和と加算和とが等しい」という条件を満たすもの

/*
    参考リンク
    ABC 098 D - Xor Sum 2
      https://atcoder.jp/contests/abc098/tasks/arc098_b
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  ll res = 0;
  int right = 0;
  int sum = 0;
  rep(left, n) {
    while (right < n && (sum ^ a[right]) == (sum + a[right])) {
      sum += a[right];
      ++right;
    }
    res += right - left;
    if (left == right)
      ++right;
    else {
      sum -= a[left];
    }
  }

  cout << res << endl;
}