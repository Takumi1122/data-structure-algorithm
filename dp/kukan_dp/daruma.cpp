#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
    参考リンク
    AIZU ONLINE JUDGE
      https://onlinejudge.u-aizu.ac.jp/problems/1611
*/

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

vector<int> w;
vector<vector<int>> dp;

int rec(int l, int r) {
  if (l == r) return 0;
  if (dp[l][r] != -1) return dp[l][r];

  if ((r - l) == 1) {
    if (abs(w[r] - w[l]) <= 1) {
      return dp[l][r] = 2;
    } else {
      return dp[l][r] = 0;
    }
  }

  int res = 0;
  if (abs(w[l] - w[r]) <= 1 && rec(l + 1, r - 1) == r - l - 1)
    chmax(res, r - l + 1);
  for (int i = l; i < r; i++) {
    chmax(res, rec(l, i) + rec(i + 1, r));
  }
  return dp[l][r] = res;
}

int main() {
  vector<int> ans;
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    w.resize(n);
    rep(i, n) cin >> w[i];
    dp.assign(n + 2, vector<int>(n + 2, -1));
    ans.push_back(rec(0, n - 1));
  }

  for (auto i : ans) {
    cout << i << endl;
  }
  return 0;
}
