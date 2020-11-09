#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 182 C - To 3
      https://atcoder.jp/contests/abc182/tasks/abc182_c
*/

int main() {
  ll n;
  cin >> n;

  string s = to_string(n);
  int ns = s.size();
  int ans = -1;
  for (int bit = 1; bit < (1 << ns); ++bit) {
    int sum = 0;
    int cnt = 0;
    rep(i, ns) {
      if (bit & (1 << i)) {
        cnt++;
        sum += s[i] - '0';
      }
    }

    if (sum % 3 == 0) ans = max(ans, cnt);
  }

  if (ans == -1) {
    cout << -1 << endl;
  } else {
    cout << ns - ans << endl;
  }
  return 0;
}