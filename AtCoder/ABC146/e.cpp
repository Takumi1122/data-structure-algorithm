#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

// 長さk以上の連続する部分列は対象外(sum % k < k のため)
// 数列全体を-1する

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

  rep(i, n) a[i]--;
  vector<int> s(n + 1);
  rep(i, n) s[i + 1] = (s[i] + a[i]) % k;

  map<int, int> mp;
  ll ans = 0;
  queue<int> q;

  rep(j, n + 1) {
    ans += mp[s[j]];
    mp[s[j]]++;
    q.push(s[j]);
    if (q.size() == k) {
      mp[q.front()]--;
      q.pop();
    }
  }

  cout << ans << endl;
  return 0;
}