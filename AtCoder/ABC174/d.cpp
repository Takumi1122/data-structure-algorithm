#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  // a: R->W, b: W->R
  int a = 0, b = 0;
  // 全てが白色と考えた場合
  rep(i, n) if (s[i] == 'R') a++;
  int ans = max(a, b);
  rep(i, n) {
    // i: 左からi+1個が赤と考えた場合
    if (s[i] == 'R')
      --a;
    else
      ++b;
    int now = max(a, b);
    ans = min(ans, now);
  }

  cout << ans << endl;
  return 0;
}
