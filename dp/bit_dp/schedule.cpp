#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 10007;
template <class T>
T add_mod(T &a, const T &b) {
  a += b;
  a %= MOD;
  return a;
}

int dp[1 << 3][1100];
int resp[1100];  // resp[i]: i日目に誰が来たか？（J:1<<0, O:1<<1, I:1<<2）

int main() {
  int n;
  string s;
  cin >> n >> s;

  rep(i, n) {
    if (s[i] == 'J') {
      resp[i + 1] = 1 << 0;
    } else if (s[i] == 'O') {
      resp[i + 1] = 1 << 1;
    } else if (s[i] == 'I') {
      resp[i + 1] = 1 << 2;
    }
  }

  dp[1][0] = 1;  // 0日目にJ君一人が来たとする
  rep(i, n) {
    rep(now, 1 << 3) {
      rep(next, 1 << 3) {
        if (now & next) {            // 2日連続で来られる人がいるか
          if (next & resp[i + 1]) {  // 責任者が来た時のみ加算
            add_mod(dp[next][i + 1], dp[now][i]);
          }
        }
      }
    }
  }

  int ans = 0;
  rep(now, 1 << 3) { add_mod(ans, dp[now][n]); }
  cout << ans << endl;
  return 0;
}
