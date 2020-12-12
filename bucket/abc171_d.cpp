#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 171 D - Replacing
      https://atcoder.jp/contests/abc171/tasks/abc171_d
*/

int main() {
  int n, q;
  cin >> n;
  ll sum = 0;
  vector<ll> num(110000, 0);
  rep(i, n) {
    ll a;
    cin >> a;
    sum += a;
    num[a]++;
  }

  cin >> q;
  rep(i, q) {
    ll b, c;
    cin >> b >> c;
    sum += (c - b) * num[b];
    num[c] += num[b];
    num[b] = 0;
    cout << sum << endl;
  }
}