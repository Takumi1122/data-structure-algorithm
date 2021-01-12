#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 108 C - Triangular Relationship
      https://atcoder.jp/contests/abc108/tasks/arc102_a
*/

int main() {
  int n, k;
  cin >> n >> k;

  // num[x]: kで割ってxあまる数が1以上n以下に何個あるか
  vector<ll> num(k, 0);
  for (int i = 1; i <= n; ++i) num[i % k]++;

  ll ans = 0;
  // kで割ったあまりで全探索
  rep(a, k) {
    int b = (k - a) % k;
    int c = (k - a) % k;
    if ((b + c) % k != 0) continue;
    ans += num[a] * num[b] * num[c];
  }

  cout << ans << endl;
  return 0;
}