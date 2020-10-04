#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

/*
    参考リンク
    ABC 158 E - Divisible Substring
      https://atcoder.jp/contests/abc158/tasks/abc158_e
*/

ll N;
string S;
int P;

ll solve() {
  if (P == 2 || P == 5) {
    ll res = 0;
    rep(i, N) if ((S[N - i - 1] - '0') % P == 0) res += N - i;
    return res;
  }

  vector<ll> val(P, 0);
  ll tenfactor = 1;
  ll cur = 0;
  val[cur]++;
  rep(i, N) {
    cur = (cur + (S[N - i - 1] - '0') * tenfactor) % P;
    tenfactor = (tenfactor * 10) % P;
    val[cur]++;
  }
  ll res = 0;
  for (int p = 0; p < P; ++p) res += val[p] * (val[p] - 1) / 2;
  return res;
}

int main() {
  cin >> N >> P >> S;
  cout << solve() << endl;
}