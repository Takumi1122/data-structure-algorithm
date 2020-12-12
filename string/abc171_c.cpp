#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 171 C - One Quadrillion and One Dalmatians
      https://atcoder.jp/contests/abc171/tasks/abc171_c
*/

int main() {
  ll n;
  cin >> n;

  string ans = "";
  while (n) {
    --n;
    ans += (char)('a' + (n % 26));
    n /= 26;
  }
  reverse(ans.begin(), ans.end());

  cout << ans << endl;
  return 0;
}