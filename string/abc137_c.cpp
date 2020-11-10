#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// アナグラム　ソートしたら同じ文字になる

/*
    参考リンク
    ABC 137 C - Green Bin
      https://atcoder.jp/contests/abc137/tasks/abc137_c
*/

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  rep(i, n) sort(s[i].begin(), s[i].end());

  ll ans = 0;
  map<string, ll> mp;
  rep(i, n) mp[s[i]]++;
  for (auto p : mp) {
    ans += p.second * (p.second - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}