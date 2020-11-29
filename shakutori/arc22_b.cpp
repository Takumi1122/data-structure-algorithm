#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// 連続する部分列のうち、「同じ数値が2箇所以上登場しない」という条件を満たす最大長

/*
    参考リンク
    ARC 022 B - 細長いお菓子
      https://atcoder.jp/contests/arc022/tasks/arc022_2
*/

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int res = 0;
  int right = 0;
  set<int> member;

  rep(left, n) {
    while (right < n && !member.count(a[right])) {
      member.insert(a[right]);
      ++right;
    }
    res = max(res, right - left);
    if (left == right)
      ++right;
    else {
      member.erase(a[left]);
    }
  }

  cout << res << endl;
}