#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    ABC 183 D - Water Heater
      https://atcoder.jp/contests/abc183/tasks/abc183_d
*/

const int MAX_T = 200005;

int main() {
  int n, w;
  cin >> n >> w;
  vector<ll> d(MAX_T);
  rep(i, n) {
    int s, t, p;
    cin >> s >> t >> p;
    d[s] += p;
    d[t] -= p;
  }

  rep(i, MAX_T - 1) d[i + 1] += d[i];
  rep(i, MAX_T) {
    if (d[i] > w) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}