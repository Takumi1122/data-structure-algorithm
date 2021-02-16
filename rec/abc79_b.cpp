#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

/*
    参考リンク
    ABC 79 B - Lucas Number
      https://atcoder.jp/contests/abc079/tasks/abc079_b
*/

ll l[90];

ll rec(ll n) {
  if (l[n] != 0) return l[n];
  ll res = rec(n - 1) + rec(n - 2);
  l[n] = res;
  return res;
}

int main() {
  ll n;
  cin >> n;
  l[0] = 2;
  l[1] = 1;
  cout << rec(n) << endl;
  return 0;
}