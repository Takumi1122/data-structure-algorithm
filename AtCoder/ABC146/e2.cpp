#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 長さk以上の連続する部分列は対象外(sum % k < k のため)
// r = j+1, l = i
// sr - sl ≡ r - l (mod k) <=> sr - r ≡ sl - l (mod k)

/*
    参考リンク
    ABC 146 E - Rem of Sum is Num
      https://atcoder.jp/contests/abc146/tasks/abc146_e
*/

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = (s[i] + a[i]) % k;

  map<int, int> mp;
  ll ans = 0;
  queue<int> q;

  rep(r, n + 1) {
    int t = (s[r] - r) % k;
    if (t < 0) t += k;
    ans += mp[t];
    mp[t]++;
    q.push(t);
    if (q.size() == k) {
      mp[q.front()]--;
      q.pop();
    }
  }

  cout << ans << endl;
  return 0;
}